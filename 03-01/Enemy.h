#pragma once
enum class EnemyState {
   APPROACH,
   FIRE,
   DISENGAGE,
};

class Enemy {
public:
   Enemy() : currentState_(EnemyState::APPROACH), isFinished_(false) {}
   void Approach();
   void Fire();
   void Disengage();
   void Update();
   bool IsFinished() const { return isFinished_; }
private:
   static void (Enemy::* spFuncTable_[])();
   EnemyState currentState_;
   bool isFinished_;
};

