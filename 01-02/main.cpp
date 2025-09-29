#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

int main() {
	// ファイルを開く
	std::ifstream file("PG3_2025_01_02.txt");
	std::vector<std::string> mailAddresses;

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

	// ファイルからメールアドレスを読み込む
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream stringstream(line);
        std::string address;

        while (std::getline(stringstream, address, ',')) {
            if (!address.empty()) {
                mailAddresses.push_back(address);
            }
        }
    }

	file.close();

	// ソートして表示
	std::sort(mailAddresses.begin(), mailAddresses.end());

	std::for_each(mailAddresses.begin(), mailAddresses.end(),
		[](const std::string& address) {
			std::cout << address << std::endl;
		}
	);

	return 0;
}