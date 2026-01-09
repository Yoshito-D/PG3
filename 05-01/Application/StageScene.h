#pragma once
#include "IScene.h"
#include <vector>


class StageScene : public IScene {
public:
   StageScene();
   ~StageScene() override = default;

   void Update() override;
   void Draw() override;

private:
};