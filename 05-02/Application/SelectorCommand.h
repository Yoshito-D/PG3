#pragma once
#include "IStageSceneCommand.h"
#include "Selector.h"
#include "Unit.h"

class SelectorMoveCommand : public IStageSceneCommand {
public:
   SelectorMoveCommand(Selector* selector, int x, int y);
   void Execute() override;
private:
   Selector* selector_;
   int x_;
   int y_;
};

class SelectUnitCommand : public IStageSceneCommand {
public:
   SelectUnitCommand(Selector* selector);
   void Execute() override;
private:
   Selector* selector_;
};

class UnitMoveCommand : public IStageSceneCommand {
public:
   UnitMoveCommand(Unit* unit, Selector* selector, int x, int y);
   void Execute() override;
private:
   Unit* unit_;
   Selector* selector_;
   int x_;
   int y_;
};

class UnitMoveEndCommand : public IStageSceneCommand {
public:
   UnitMoveEndCommand(Unit* unit, Selector* selector);
   void Execute() override;
private:
   Unit* unit_;
   Selector* selector_;
};