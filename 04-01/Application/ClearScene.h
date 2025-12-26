#pragma once
#include "IScene.h"

class ClearScene : public IScene {
public:
   ClearScene();
   ~ClearScene() override = default;

   void Update() override;
   void Draw() override;
};