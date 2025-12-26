#include "IScene.h"

SCENE IScene::sceneType_ = SCENE::TITLE;

IScene::IScene() {}

SCENE IScene::GetSceneType() {
   return sceneType_;
}