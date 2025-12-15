#include <iostream>
#include <algorithm>

template<typename T>
T Min(const T& num1 ,const T& num2) {
    return (num1 < num2) ? num1 : num2;
}

int main() {
	std::cout << Min(8, 7) << std::endl;       // int
	std::cout << Min(3.5f, 2.5f) << std::endl; // float
	std::cout << Min(1.2, 5.7) << std::endl;   // double

    return 0;
}