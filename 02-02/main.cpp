#include <iostream>

/// @brief 2つの異なる方法で計算された時給を比較
/// @param time 労働時間（時間単位）
/// @param recursiveHourlyWage 再帰的な方法で計算された時給
/// @param recursiveTotalWage 再帰的な方法で計算された総賃金
/// @param generalHourlyWage 一般的な方法で計算された時給
/// @param generalTotalWage 一般的な方法で計算された総賃金
/// @return 再帰的な賃金体系が一般的な賃金体系を上回ったときの時間
int32_t CompareHourlyWages(int32_t time, int32_t recursiveHourlyWage, int32_t recursiveTotalWage,
   int32_t generalHourlyWage, int32_t generalTotalWage);

/// @brief 指定された賃金情報を出力
/// @param time 時間（単位: 時間）
/// @param recursiveHourlyWage 再帰的な時給
/// @param recursiveTotalWage 再帰的な合計賃金
/// @param generalHourlyWage 一般的な時給
/// @param generalTotalWage 一般的な合計賃金
void PrintWages(int32_t time, int32_t recursiveHourlyWage, int32_t recursiveTotalWage,
   int32_t generalHourlyWage, int32_t generalTotalWage);

int main() {
   std::cout << CompareHourlyWages(100, 1, 1226, 0, 0) << "時間で逆転" << std::endl;
}

int32_t CompareHourlyWages(int32_t time, int32_t recursiveHourlyWage, int32_t recursiveTotalWage,
   int32_t generalHourlyWage, int32_t generalTotalWage) {
   recursiveTotalWage += recursiveHourlyWage;
   generalTotalWage += generalHourlyWage;

   PrintWages(time, recursiveHourlyWage, recursiveTotalWage, generalHourlyWage, generalTotalWage);

   if (recursiveTotalWage >= generalTotalWage) {
	  return time;
   }

   return CompareHourlyWages(recursiveHourlyWage * 2 - 50, time + 1, generalHourlyWage,
	  recursiveTotalWage, generalTotalWage);
}

void PrintWages(int32_t time, int32_t recursiveHourlyWage, int32_t recursiveTotalWage, int32_t generalHourlyWage, int32_t generalTotalWage) {
   std::cout << time << "時間目" << std::endl;
   std::cout << "再帰的な賃金体系：" << "時給 = " << recursiveHourlyWage << " 合計 = " << recursiveTotalWage << std::endl;
   std::cout << "一般的な賃金体系：" << "時給 = " << generalHourlyWage << " 合計 = " << generalTotalWage << "\n" << std::endl;
}

