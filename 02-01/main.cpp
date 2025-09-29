#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
	std::cout << Min(8, 7) << std::endl;       // int
	std::cout << Min(3.5f, 2.5f) << std::endl; // float
	std::cout << Min(1.2, 5.7) << std::endl;   // double

    return 0;
}