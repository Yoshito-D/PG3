#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y)
   : selector_(selector), x_(x), y_(y) {
}

void SelectorMoveCommand::Execute() {
   selector_->Move(x_, y_);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector)
   : selector_(selector) {
}

void SelectUnitCommand::Execute() {
   selector_->SelectUnit();
}

UnitMoveCommand::UnitMoveCommand(Unit* unit, Selector* selector, int x, int y)
   : unit_(unit), selector_(selector), x_(x), y_(y) {
}

void UnitMoveCommand::Execute() {
   unit_->Move(x_, y_);
   selector_->Move(x_, y_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector)
   : unit_(unit), selector_(selector) {
}

void UnitMoveEndCommand::Execute() {
   unit_->MoveEnd(selector_);
}
