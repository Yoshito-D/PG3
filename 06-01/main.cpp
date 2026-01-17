#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int main() {
    std::mutex m;
    std::condition_variable cv;
    int current = 1;

    auto worker = [&](int id) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [&]{ return current == id; });
        std::cout << "thread " << id << std::endl;
        ++current;
        lk.unlock();
        cv.notify_all();
    };

    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}