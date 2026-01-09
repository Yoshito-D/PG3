#pragma once
struct Vector2 {
   float x;
   float y;
};

class Player {
public:
   Player();
   void Update();
   void Draw();

   void MoveRight();
   void MoveLeft();
private:
   Vector2 pos_;
   float speed_;
};

