#pragma once
#include "IScene.h"
#include <memory>
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"

class StageScene : public IScene {
public:
   StageScene();
   ~StageScene() override = default;

   void Update() override;
   void Draw() override;

private:
   std::unique_ptr<InputHandler> inputHandler_;
   std::unique_ptr<Player> player_;
   ICommand* iCommand_;
};