#include "InputManager.h"
#include <cstring>

InputManager& InputManager::GetInstance() {
   static InputManager instance;
   return instance;
}

InputManager::InputManager() {
   currKeys_.fill(0);
   prevKeys_.fill(0);
}

InputManager::~InputManager() {}

void InputManager::Update() {
   prevKeys_ = currKeys_;

   char keyBuf[256];
   Novice::GetHitKeyStateAll(keyBuf);
   for (int i = 0; i < kKeyCount; ++i) {
	  currKeys_[i] = static_cast<uint8_t>(keyBuf[i]);
   }
}

bool InputManager::IsKeyDown(int keyCode) const {
   return currKeys_[keyCode] != 0;
}
bool InputManager::IsKeyTrigger(int keyCode) const {
   return currKeys_[keyCode] != 0 && prevKeys_[keyCode] == 0;
}

bool InputManager::IsKeyRelease(int keyCode) const {
   return currKeys_[keyCode] == 0 && prevKeys_[keyCode] != 0;
}
