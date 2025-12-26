#include <algorithm>
#include <iostream>

template <typename T1, typename T2>
class MinContainer {
public:
   MinContainer(T1 num1, T2 num2) : num1(num1), num2(num2) {}
   T1 Min() { return static_cast<T1>(std::min(num1, static_cast<T1>(num2))); }
private:
   T1 num1;
   T2 num2;
};

int main() {
   MinContainer<int, double> minContainer1(5, 4.5);
   MinContainer<int, float> minContainer2(3, 4.5f);
   MinContainer<double, int> minContainer3(9.3, 8);
   MinContainer<double, float> minContainer4(8.0, 6.3f);
   MinContainer<float, double> minContainer5(9.3f, 4.09);
   MinContainer<float, int> minContainer6(12.3f, 12);

   std::cout << "minContainer1.Min(): " << minContainer1.Min() << std::endl;
   std::cout << "minContainer2.Min(): " << minContainer2.Min() << std::endl;
   std::cout << "minContainer3.Min(): " << minContainer3.Min() << std::endl;
   std::cout << "minContainer4.Min(): " << minContainer4.Min() << std::endl;
   std::cout << "minContainer5.Min(): " << minContainer5.Min() << std::endl;
   std::cout << "minContainer6.Min(): " << minContainer6.Min() << std::endl;

   return 0;
}