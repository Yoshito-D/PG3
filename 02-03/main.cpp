#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

void ShowResult(int roll, int userGuess);

int main() {
   srand((unsigned)time(NULL));
   int userGuess = 0;
   std::cout << "半か丁かを選択してください。半（奇数）= 1 ,丁（偶数）= 0" << std::endl;
   scanf_s("%d", &userGuess);
   int roll = (rand() % 6) + 1;
   DelayReveal(ShowResult, 3000, roll, userGuess);

   return 0;
}

void DelayReveal(void(*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
   Sleep(delayMs);
   fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
   std::cout << "出目は " << roll << " でした。" << std::endl;
   std::cout << ((roll % 2 == userGuess) ? "正解" : "不正解") << std::endl;
}
