#include "Enemy.h"
#include <iostream>
void (Enemy::* Enemy::spFuncTable_[])() = {
   &Enemy::Approach,
   &Enemy::Fire,
   &Enemy::Disengage
};

void Enemy::Approach() {
   std::cout << "接近" << std::endl;
   currentState_ = EnemyState::FIRE;
}

void Enemy::Fire() {
   std::cout << "射撃" << std::endl;
   currentState_ = EnemyState::DISENGAGE;
}

void Enemy::Disengage() {
   std::cout << "離脱" << std::endl;
   isFinished_ = true;
   std::cout << "敵の行動終了" << std::endl;
}

void Enemy::Update() {
   (this->*Enemy::spFuncTable_[static_cast<size_t>(currentState_)])();
}
