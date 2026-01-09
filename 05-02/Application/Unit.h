#pragma once

class Selector;

class Unit {
public:
   Unit() = default;
   void Init(int idref);
   void Update();
   void Draw();

   void Move(int x, int y);
   void MoveEnd(Selector* selector);

   int GetMapX() const { return mapX_; }
   int GetMapY() const { return mapY_; }

   int GetId() const { return id_; }
   bool IsSelected() const { return isSelected_; }

   bool GetSelected() const { return isSelected_; }
   void SetSelected(bool isSelected) { isSelected_ = isSelected; }

private:
   int mapX_ = 0;
   int mapY_ = 0;
   int mapSize = 32;
   int id_ = 0;
   bool isSelected_ = false;
};