#pragma once
#include "IScene.h"
#include <memory>

class GameManager {
public:
   GameManager();
   ~GameManager();

   void Run();

   void ChangeScene(SCENE type);

private:
   std::unique_ptr<IScene> currentScene_;
   SCENE prevSceneType_;
};