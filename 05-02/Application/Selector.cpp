#include "Selector.h"
#include <Novice.h>

Selector::Selector() {
   mapX_ = 0;
   mapY_ = 0;
   mapSize_ = 32;
   selectMode_ = SELECTOR;
   units_ = nullptr;
   selectedUnit_ = nullptr;
}

void Selector::Init() {
   mapX_ = 0;
   mapY_ = 0;
   selectMode_ = SELECTOR;
   selectedUnit_ = nullptr;
}

void Selector::Update() {
}

void Selector::Draw() {
   // Only draw selector in SELECTOR mode
   if (selectMode_ == SELECTOR) {
      Novice::DrawBox(mapX_, mapY_, mapSize_, mapSize_, 0.0f, 0xFF6688FF, kFillModeWireFrame);
   }
}

void Selector::Move(int x, int y) {
   mapX_ += x;
   mapY_ += y;
   if (mapX_ < 0) {
      mapX_ = 0;
   }
   if (mapY_ < 0) {
      mapY_ = 0;
   }
   if (mapX_ > 1280 - mapSize_) {
      mapX_ = 1280 - mapSize_;
   }
   if (mapY_ > 720 - mapSize_) {
      mapY_ = 720 - mapSize_;
   }
}

void Selector::SelectUnit() {
   if (!units_) return;
   
   // Check if selector is on a unit
   for (const auto& unit : *units_) {
      if (unit->GetMapX() == mapX_ && unit->GetMapY() == mapY_) {
         // Select this unit
         unit->SetSelected(true);
         selectedUnit_ = unit.get();
         selectMode_ = UNIT;
         return;
      }
   }
}