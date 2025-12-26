#include <algorithm>
#include <iostream>

template <typename T1, typename T2>
class Class {
public:
   Class(T1 num1, T2 num2) : num1(num1), num2(num2) {}
   T1 Min() { return static_cast<T1>(std::min(num1, static_cast<T1>(num2))); }
private:
   T1 num1;
   T2 num2;
};

int main() {
   Class<int, double> class1(5, 4.5);
   Class<int, float> class2(3, 4.5f);
   Class<double, int> class3(9.3, 8);
   Class<double, float> class4(8.0, 6.3f);
   Class<float, double> class5(9.3f, 4.09);
   Class<float, int> class6(12.3f, 12);

   std::cout << "class1.Min(): " << class1.Min() << std::endl;
   std::cout << "class2.Min(): " << class2.Min() << std::endl;
   std::cout << "class3.Min(): " << class3.Min() << std::endl;
   std::cout << "class4.Min(): " << class4.Min() << std::endl;
   std::cout << "class5.Min(): " << class5.Min() << std::endl;
   std::cout << "class6.Min(): " << class6.Min() << std::endl;

   return 0;
}