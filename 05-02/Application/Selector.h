#pragma once
#include "Unit.h"
#include <vector>
#include <memory>

enum CommandType  {
   SELECTOR,
   UNIT
};

class Selector {
public:
   Selector();
   ~Selector() = default;
   void Init();
   void Update();
   void Draw();

   void Move(int x, int y);
   void SelectUnit();
   
   void SetUnits(const std::vector<std::unique_ptr<Unit>>& units) { units_ = &units; }

   int GetSelectMode() const { return selectMode_; }
   void SetSelectMode(int mode) { selectMode_ = mode; }
    
   Unit* GetSelectedUnitAddress() const { return selectedUnit_; }
   
   int GetMapX() const { return mapX_; }
   int GetMapY() const { return mapY_; }
   
private:
   int mapX_;
   int mapY_;
   int mapSize_;

   int selectMode_;

   const std::vector<std::unique_ptr<Unit>>* units_;
   Unit* selectedUnit_;
};