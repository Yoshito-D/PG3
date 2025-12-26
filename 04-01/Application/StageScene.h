#pragma once
#include "IScene.h"
#include <vector>

struct Player {
   float positionX, positionY;
   float moveSpeed;
};

struct Bullet {
   float positionX, positionY;
   float velocityX, velocityY;
   bool isActive;
};

struct Enemy {
   float positionX, positionY;
   float velocityX, velocityY;
   bool isActive;
};

class StageScene : public IScene {
public:
   StageScene();
   ~StageScene() override = default;

   void Update() override;
   void Draw() override;

private:
   void UpdatePlayer();
   void UpdateBullets();
   void UpdateEnemies();
   void CheckCollisions();

   Player player_;
   std::vector<Bullet> bullets_;
   std::vector<Enemy> enemies_;
   int frameCount_;
};