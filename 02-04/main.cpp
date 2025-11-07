#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <functional>

int main() {
   srand((unsigned)time(NULL));

   int userGuess = 0;

   std::cout << "半か丁かを選択してください。半（奇数）= 1 ,丁（偶数）= 0" << std::endl;
   scanf_s("%d", &userGuess);

   int roll = (rand() % 6) + 1;

   std::function<void(int, int)> showResultFunc =
	  [](int roll, int userGuess) {
	  std::cout << "出目は " << roll << " でした。" << std::endl;
	  std::cout << ((roll % 2 == userGuess) ? "正解" : "不正解") << std::endl;
	  };

   std::function<void(std::function<void(int, int)>, unsigned int, int, int)> delayRevealFunc =
	  [](std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
	  Sleep(delayMs);
	  fn(roll, userGuess);
	  };

   delayRevealFunc(showResultFunc, 3000, roll, userGuess);

   return 0;
}
