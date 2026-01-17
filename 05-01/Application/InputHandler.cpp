#include "InputHandler.h"
#include <Novice.h>

ICommand* InputHandler::HandleInput() {

   if (Novice::CheckHitKey(DIK_A)) {
	  return pressKeyA_.get();
   }
   if (Novice::CheckHitKey(DIK_D)) {
	  return pressKeyD_.get();
   }
   return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
   pressKeyA_ = std::make_unique<MoveLeftCommand>();
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
   pressKeyD_ = std::make_unique<MoveRightCommand>();
}