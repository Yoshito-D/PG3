#pragma once
#include <array>
#include <Novice.h>
#include <cstdint>

class InputManager {
public:
   static InputManager& GetInstance();

   void Update();

   bool IsKeyDown(int keyCode) const;
   bool IsKeyTrigger(int keyCode) const;
   bool IsKeyRelease(int keyCode) const;

private:
   InputManager();
   ~InputManager();
   InputManager(const InputManager&) = delete;
   InputManager& operator=(const InputManager&) = delete;

   static const int kKeyCount = 256;

   std::array<uint8_t, kKeyCount> currKeys_;
   std::array<uint8_t, kKeyCount> prevKeys_;
};
