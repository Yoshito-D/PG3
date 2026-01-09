#include "StageSceneInputHandler.h"
#include "SelectorCommand.h"
#include <Novice.h>

StageSceneInputHandler::StageSceneInputHandler() {
	selector_ = nullptr;
	selectedUnit_ = nullptr;
	currKeys_.fill(0);
	prevKeys_.fill(0);
}

void StageSceneInputHandler::UpdateKeyStage() {
   prevKeys_ = currKeys_;

   char keyBuf[256];
   Novice::GetHitKeyStateAll(keyBuf);
   for (int i = 0; i < kKeyCount; ++i) {
	  currKeys_[i] = static_cast<uint8_t>(keyBuf[i]);
   }
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
	selector_ = selector;
	
	// Arrow keys movement
	if (currKeys_[DIK_W] && !prevKeys_[DIK_W]) {
		return new SelectorMoveCommand(selector_, 0, -32);
	}
	if (currKeys_[DIK_S] && !prevKeys_[DIK_S]) {
		return new SelectorMoveCommand(selector_, 0, 32);
	}
	if (currKeys_[DIK_A] && !prevKeys_[DIK_A]) {
		return new SelectorMoveCommand(selector_, -32, 0);
	}
	if (currKeys_[DIK_D] && !prevKeys_[DIK_D]) {
		return new SelectorMoveCommand(selector_, 32, 0);
	}
	
	// Space key to select unit
	if (currKeys_[DIK_SPACE] && !prevKeys_[DIK_SPACE]) {
		return new SelectUnitCommand(selector_);
	}
	
	return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
	selectedUnit_ = unit;
	
	// Arrow keys movement
	if (currKeys_[DIK_W] && !prevKeys_[DIK_W]) {
		return new UnitMoveCommand(unit, selector_, 0, -32);
	}
	if (currKeys_[DIK_S] && !prevKeys_[DIK_S]) {
		return new UnitMoveCommand(unit, selector_, 0, 32);
	}
	if (currKeys_[DIK_A] && !prevKeys_[DIK_A]) {
		return new UnitMoveCommand(unit, selector_, -32, 0);
	}
	if (currKeys_[DIK_D] && !prevKeys_[DIK_D]) {
		return new UnitMoveCommand(unit, selector_, 32, 0);
	}
	
	// Space key to end unit movement
	if (currKeys_[DIK_SPACE] && !prevKeys_[DIK_SPACE]) {
		return new UnitMoveEndCommand(unit, selector_);
	}
	
	return nullptr;
}

bool StageSceneInputHandler::CheckUndoStatus() {
	// Ctrl+Z for undo
	if ((currKeys_[DIK_LCONTROL] || currKeys_[DIK_RCONTROL]) && currKeys_[DIK_Z] && !prevKeys_[DIK_Z]) {
		return true;
	}
	return false;
}