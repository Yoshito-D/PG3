#include <iostream>
#include "Enemy.h"

int main() {
   Enemy enemy;
   while (!enemy.IsFinished()) {
	  enemy.Update();
   }
   return 0;
}