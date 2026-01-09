#include "StageScene.h"
#include <Novice.h>

StageScene::StageScene() {
   inputHandler_ = std::make_unique<StageSceneInputHandler>();
   selector_ = std::make_unique<Selector>();
   command_ = nullptr;
   undoCount_ = 0;
   
   // Initialize command history iterator
   commandHistoryItr_ = commandHistory_.end();
   
   // Initialize units at various positions
   units_.push_back(std::make_unique<Unit>());
   units_[0]->Init(0);
   units_[0]->Move(64, 96);  // Position for first unit (pink in screenshot)
   
   units_.push_back(std::make_unique<Unit>());
   units_[1]->Init(1);
   units_[1]->Move(928, 32);  // Position for second unit
   
   units_.push_back(std::make_unique<Unit>());
   units_[2]->Init(2);
   units_[2]->Move(992, 224);  // Position for third unit
   
   units_.push_back(std::make_unique<Unit>());
   units_[3]->Init(3);
   units_[3]->Move(352, 448);  // Position for fourth unit
   
   units_.push_back(std::make_unique<Unit>());
   units_[4]->Init(4);
   units_[4]->Move(64, 512);  // Position for fifth unit
   
   // Pass units to selector
   selector_->SetUnits(units_);
}

StageScene::~StageScene() {
   // Clean up command history
   for (auto command : commandHistory_) {
      delete command;
   }
   commandHistory_.clear();
}

void StageScene::Update() {
   inputHandler_->UpdateKeyStage();

   command_ = nullptr;

   if (selector_->GetSelectMode() == SELECTOR) {
      command_ = inputHandler_->SelectorHandleInput(selector_.get());
   } else if (selector_->GetSelectMode() == UNIT) {
      command_ = inputHandler_->UnitHandleInput(selector_->GetSelectedUnitAddress());
   }

   if (command_) {
      command_->Execute();
      
      // Add to command history
      if (commandHistoryItr_ != commandHistory_.end()) {
         // Remove commands after current position
         auto it = commandHistoryItr_;
         while (it != commandHistory_.end()) {
            delete *it;
            it = commandHistory_.erase(it);
         }
      }
      
      commandHistory_.push_back(command_);
      commandHistoryItr_ = commandHistory_.end();
      undoCount_ = 0;
   }

   // Handle undo - only allow in UNIT mode (when a unit is selected)
   if (inputHandler_->CheckUndoStatus() && selector_->GetSelectMode() == UNIT) {
      if (!commandHistory_.empty() && commandHistoryItr_ != commandHistory_.begin()) {
         --commandHistoryItr_;
         undoCount_++;
         
         // Re-execute all commands from beginning to current position
         selector_->Init();
         for (auto& unit : units_) {
            unit->Init(unit->GetId());
         }
         
         // Re-position units
         if (units_.size() > 0) units_[0]->Move(64, 96);
         if (units_.size() > 1) units_[1]->Move(928, 32);
         if (units_.size() > 2) units_[2]->Move(992, 224);
         if (units_.size() > 3) units_[3]->Move(352, 448);
         if (units_.size() > 4) units_[4]->Move(64, 512);
         
         auto it = commandHistory_.begin();
         while (it != commandHistoryItr_) {
            (*it)->Execute();
            ++it;
         }
      }
   }
   
   // Update units
   for (auto& unit : units_) {
      unit->Update();
   }
   
   selector_->Update();
}

void StageScene::Draw() {
   // Draw grid with white lines
   for (int x = 0; x < 1280; x += 32) {
      Novice::DrawLine(x, 0, x, 720, 0xFFFFFFFF);
   }
   for (int y = 0; y < 720; y += 32) {
      Novice::DrawLine(0, y, 1280, y, 0xFFFFFFFF);
   }
   
   // Draw units
   for (auto& unit : units_) {
      unit->Draw();
   }
   
   // Draw selector
   selector_->Draw();
   
   // Draw instructions
   if (selector_->GetSelectMode() == SELECTOR) {
      Novice::ScreenPrintf(10, 690, "WASD|arrow keys: move / space key: change selector mode");
   } else if (selector_->GetSelectMode() == UNIT) {
      Novice::ScreenPrintf(10, 690, "WASD|arrow keys: move / space key: change unit mode / ctrl+z: undo");
      if (!commandHistory_.empty()) {
         int remainingUndos = static_cast<int>(std::distance(commandHistory_.begin(), commandHistoryItr_));
         if (remainingUndos > 0) {
            Novice::ScreenPrintf(10, 710, "You have %d more 'UnDo' actions available.", remainingUndos);
         }
      }
   }
}