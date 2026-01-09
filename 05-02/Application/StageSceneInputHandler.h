#pragma once
#include "IStageSceneCommand.h"
#include "Selector.h"
#include "Unit.h"
#include <array>
#include <cstdint>

class StageSceneInputHandler {
public:
   StageSceneInputHandler();
   void UpdateKeyStage();

   IStageSceneCommand* SelectorHandleInput(Selector* selector);
   IStageSceneCommand* UnitHandleInput(Unit *unit);

   bool CheckUndoStatus();

private:
   static const int kKeyCount = 256;

   std::array<uint8_t, kKeyCount> currKeys_;
   std::array<uint8_t, kKeyCount> prevKeys_;

   Selector* selector_ = nullptr;
   Unit* selectedUnit_ = nullptr;
};