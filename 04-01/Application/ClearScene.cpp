#include "ClearScene.h"
#include "InputManager.h"
#include <Novice.h>

ClearScene::ClearScene() : IScene() {
   IScene::sceneType_ = SCENE::CLEAR;
}

void ClearScene::Update() {
   if (InputManager::GetInstance().IsKeyTrigger(DIK_SPACE)) {
	  IScene::sceneType_ = SCENE::TITLE;
   }
}

void ClearScene::Draw() {
   Novice::ScreenPrintf(600, 360, "CLEAR!");
   Novice::ScreenPrintf(550, 400, "Press SPACE to Title");
}