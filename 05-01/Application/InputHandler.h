#pragma once
#include <memory>
#include "Command.h"

class InputHandler {
public:
   ICommand* HandleInput();

   void AssignMoveLeftCommand2PressKeyA();
   void AssignMoveRightCommand2PressKeyD();

private:
   std::unique_ptr<ICommand> pressKeyA_;
   std::unique_ptr<ICommand> pressKeyD_;
};