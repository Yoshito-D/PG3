#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:
   TitleScene();
   ~TitleScene() override = default;

   void Update() override;
   void Draw() override;
};