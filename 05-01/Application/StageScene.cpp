#include "StageScene.h"

StageScene::StageScene()
	: inputHandler_(std::make_unique<InputHandler>()),
	  player_(std::make_unique<Player>()),
	  iCommand_(nullptr) {
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
}

void StageScene::Update() {
	iCommand_ = inputHandler_->HandleInput();
	if (iCommand_) {
		iCommand_->Execute(*player_.get());
	}
	player_->Update();
}

void StageScene::Draw() {
	player_->Draw();
}