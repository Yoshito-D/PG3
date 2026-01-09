#include "IScene.h"

SCENE IScene::sceneType_ = SCENE::STAGE;

IScene::IScene() {}

SCENE IScene::GetSceneType() {
   return sceneType_;
}