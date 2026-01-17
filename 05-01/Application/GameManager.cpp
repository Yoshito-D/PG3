#include "GameManager.h"
#include "IScene.h"
#include "StageScene.h"
#include <Novice.h>

GameManager::GameManager() : prevSceneType_(SCENE::STAGE) {
   ChangeScene(SCENE::STAGE);
}

GameManager::~GameManager() {}

void GameManager::Run() {

   // ウィンドウの×ボタンが押されるまでループ
   while (Novice::ProcessMessage() == 0) {
	  // フレームの開始
	  Novice::BeginFrame();

	  SCENE currentType = IScene::GetSceneType();
	  if (currentType != prevSceneType_) {
		 ChangeScene(currentType);
		 prevSceneType_ = currentType;
	  }

	  if (currentScene_) {
		 currentScene_->Update();
	  }

	  if (currentScene_) {
		 currentScene_->Draw();
	  }

	  // フレームの終了
	  Novice::EndFrame();

	  // ESCキーが押されたらループを抜ける
	  if (Novice::CheckHitKey(DIK_ESCAPE) == 1) {
		 break;
	  }
   }
}

void GameManager::ChangeScene(SCENE type) {
   switch (type) {
	  case SCENE::STAGE:
		 currentScene_ = std::make_unique<StageScene>();
		 break;
   }
}