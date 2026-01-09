#include "Unit.h"
#include <Novice.h>
#include "Selector.h"

void Unit::Init(int idref) {
   id_ = idref;
   mapX_ = 0;
   mapY_ = 0;
   isSelected_ = false;
}

void Unit::Update() {}

void Unit::Draw() {
   if (isSelected_) {
	  Novice::DrawBox(mapX_ + 4, mapY_ + 4, 24, 24, 0.0f, 0xFF0000FF, kFillModeSolid);
   } else {
	  Novice::DrawBox(mapX_ + 4, mapY_ + 4, 24, 24, 0.0f, 0xFFFFFFFF, kFillModeSolid);
   }
}

void Unit::Move(int x, int y) {
   mapX_ += x;
   mapY_ += y;
   if (mapX_ < 0) {
	  mapX_ = 0;
   }
   if (mapY_ < 0) {
	  mapY_ = 0;
   }
   if (mapX_ > 1280 - mapSize) {
	  mapX_ = 1280 - mapSize;
   }
   if (mapY_ > 720 - mapSize) {
	  mapY_ = 720 - mapSize;
   }
}

void Unit::MoveEnd(Selector* selector) {
   isSelected_ = false;
   selector->SetSelectMode(SELECTOR);
}