#include "TitleScene.h"
#include "InputManager.h"
#include <Novice.h>

TitleScene::TitleScene() : IScene() {
   IScene::sceneType_ = SCENE::TITLE;
}

void TitleScene::Update() {
   if (InputManager::GetInstance().IsKeyTrigger(DIK_SPACE)) {
	  IScene::sceneType_ = SCENE::STAGE;
   }
}

void TitleScene::Draw() {
   Novice::ScreenPrintf(600, 360, "TITLE");
   Novice::ScreenPrintf(550, 400, "Press SPACE to Start");
}