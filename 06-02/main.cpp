#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <queue>
#include <condition_variable>

using Map = std::vector<std::vector<int>>;

void LoadCSV(const std::string& path,
   std::queue<std::vector<int>>& outQueue,
   std::mutex& queueMutex,
   std::condition_variable& cv,
   std::atomic<bool>& finished) {
   std::ifstream ifs(path);
   if (!ifs.is_open()) {
	  std::cerr << "CSVを開けませんでした: " << path << std::endl;
	  finished = true;
	  cv.notify_all();
	  return;
   }

   std::string line;
   while (std::getline(ifs, line)) {
	  std::istringstream ss(line);
	  std::string token;
	  std::vector<int> row;
	  while (std::getline(ss, token, ',')) {
		 try {
			int v = std::stoi(token);
			row.push_back(v);
		 }
		 catch (...) {
			row.push_back(0);
		 }
	  }
	  if (!row.empty()) {
		 {
			std::lock_guard<std::mutex> lk(queueMutex);
			outQueue.push(row);
		 }
		 cv.notify_one();
	  }
	  // デモ用に遅延を入れる
	  std::this_thread::sleep_for(std::chrono::milliseconds(20));
   }

   finished = true;
   cv.notify_all();
}

void RenderMap(const Map& map) {
   for (const auto& row : map) {
	  for (int cell : row) {
		 char ch = ' ';
		 switch (cell) {
			case 0: ch = '.'; break;
			case 1: ch = '#'; break;
			case 2: ch = '~'; break;
			case 3: ch = '*'; break;
			default: ch = '?'; break;
		 }
		 std::cout << ch;
	  }
	  std::cout << '\n';
   }
}

int main() {
   std::string csvPath = "map.csv";

   Map mapData;

   std::queue<std::vector<int>> rowQueue;
   std::mutex queueMutex;
   std::condition_variable cv;
   std::atomic<bool> finished(false);

   std::thread loader;

   std::ifstream test(csvPath);
   if (!test.is_open()) {
	  std::cerr << "CSVが見つかりませんでした ('" << csvPath << "')。読み込みに失敗しました。\n";
	  return 0;
   }

   test.close();
   std::cout << "CSVを発見: " << csvPath << std::endl;

   loader = std::thread(LoadCSV, csvPath, std::ref(rowQueue), std::ref(queueMutex), std::ref(cv), std::ref(finished));

   while (true) {
	  std::unique_lock<std::mutex> lk(queueMutex);
	  cv.wait(lk, [&]() { return !rowQueue.empty() || finished.load(); });

	  while (!rowQueue.empty()) {
		 auto row = rowQueue.front();
		 rowQueue.pop();
		 lk.unlock();

		 mapData.push_back(std::move(row));

		 lk.lock();
	  }

	  if (finished.load() && rowQueue.empty()) break;
   }

   if (loader.joinable()) loader.join();

   std::cout << "\nCSV読み込み完了。マップを表示します:\n\n";

   if (mapData.empty()) {
	  std::cout << "マップが空か、読み込みに失敗しました。\n";
	  return 0;
   }
   RenderMap(mapData);

   return 0;
}