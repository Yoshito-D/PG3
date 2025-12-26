#include "GameManager.h"
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "InputManager.h"
#include <Novice.h>

GameManager::GameManager() : prevSceneType_(SCENE::TITLE) {
   ChangeScene(SCENE::TITLE);
}

GameManager::~GameManager() {}

void GameManager::Run() {

   // ウィンドウの×ボタンが押されるまでループ
   while (Novice::ProcessMessage() == 0) {
	  // フレームの開始
	  Novice::BeginFrame();

	  InputManager::GetInstance().Update();

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
	  case SCENE::TITLE:
		 currentScene_ = std::make_unique<TitleScene>();
		 break;
	  case SCENE::STAGE:
		 currentScene_ = std::make_unique<StageScene>();
		 break;
	  case SCENE::CLEAR:
		 currentScene_ = std::make_unique<ClearScene>();
		 break;
   }
}