#include "StageScene.h"
#include "InputManager.h"
#include <Novice.h>
#include <algorithm>

StageScene::StageScene() : IScene(), frameCount_(0) {
   IScene::sceneType_ = SCENE::STAGE;
   bullets_.clear();
   enemies_.clear();
   frameCount_ = 0;
   player_.positionX = 640.0f;
   player_.positionY = 600.0f;
   player_.moveSpeed = 5.0f;
}

void StageScene::Update() {
   UpdatePlayer();
   UpdateBullets();
   UpdateEnemies();
   CheckCollisions();
   frameCount_++;
}

void StageScene::UpdatePlayer() {
   if (InputManager::GetInstance().IsKeyDown(DIK_W)) player_.positionY -= player_.moveSpeed;
   if (InputManager::GetInstance().IsKeyDown(DIK_S)) player_.positionY += player_.moveSpeed;
   if (InputManager::GetInstance().IsKeyDown(DIK_A)) player_.positionX -= player_.moveSpeed;
   if (InputManager::GetInstance().IsKeyDown(DIK_D)) player_.positionX += player_.moveSpeed;

   player_.positionX = player_.positionX < 0.0f ? 0.0f : (player_.positionX > 1280.0f - 32.0f ? 1280.0f - 32.0f : player_.positionX);
   player_.positionY = player_.positionY < 0.0f ? 0.0f : (player_.positionY > 720.0f - 32.0f ? 720.0f - 32.0f : player_.positionY);

   if (InputManager::GetInstance().IsKeyTrigger(DIK_SPACE)) {
	  bullets_.push_back({ player_.positionX + 16.0f, player_.positionY, 0.0f, -10.0f, true });
   }
}

void StageScene::UpdateBullets() {
   for (auto& bullet : bullets_) {
	  if (bullet.isActive) {
		 bullet.positionY += bullet.velocityY;
		 if (bullet.positionY < 0) bullet.isActive = false;
	  }
   }
   bullets_.erase(std::remove_if(bullets_.begin(), bullets_.end(), [](const Bullet& b) { return !b.isActive; }), bullets_.end());
}

void StageScene::UpdateEnemies() {
   if (frameCount_ % 60 == 0) {
	  enemies_.push_back({ static_cast<float>(rand() % 1280), 0.0f, 0.0f, 2.0f, true });
   }

   for (auto& enemy : enemies_) {
	  if (enemy.isActive) {
		 enemy.positionY += enemy.velocityY;
		 if (enemy.positionY > 720) enemy.isActive = false;
	  }
   }
   enemies_.erase(std::remove_if(enemies_.begin(), enemies_.end(), [](const Enemy& e) { return !e.isActive; }), enemies_.end());
}

void StageScene::CheckCollisions() {
   for (auto& bullet : bullets_) {
	  if (!bullet.isActive) continue;
	  for (auto& enemy : enemies_) {
		 if (!enemy.isActive) continue;
		 if (bullet.positionX < enemy.positionX + 32 && bullet.positionX + 8 > enemy.positionX &&
			bullet.positionY < enemy.positionY + 32 && bullet.positionY + 8 > enemy.positionY) {
			bullet.isActive = false;
			enemy.isActive = false;
			IScene::sceneType_ = SCENE::CLEAR;
			return;
		 }
	  }
   }
}

void StageScene::Draw() {
   Novice::DrawBox(static_cast<int>(player_.positionX), static_cast<int>(player_.positionY), 32, 32, 0.0f, 0xFFFFFFFF, kFillModeSolid);

   for (const auto& bullet : bullets_) {
	  if (bullet.isActive) {
		 Novice::DrawBox(static_cast<int>(bullet.positionX), static_cast<int>(bullet.positionY), 8, 8, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	  }
   }

   for (const auto& enemy : enemies_) {
	  if (enemy.isActive) {
		 Novice::DrawBox(static_cast<int>(enemy.positionX), static_cast<int>(enemy.positionY), 32, 32, 0.0f, 0xFF0000FF, kFillModeSolid);
	  }
   }
}