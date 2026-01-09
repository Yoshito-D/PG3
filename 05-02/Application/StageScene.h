#pragma once
#include "IScene.h"
#include <vector>
#include <list>
#include <memory>
#include "IStageSceneCommand.h"
#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "Unit.h"

class StageScene : public IScene {
public:
   StageScene();
   ~StageScene() override;

   void Update() override;
   void Draw() override;

private:
   std::unique_ptr<StageSceneInputHandler> inputHandler_;
   IStageSceneCommand* command_;
   std::list<IStageSceneCommand*> commandHistory_;
   std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

   std::unique_ptr<Selector> selector_;
   std::vector<std::unique_ptr<Unit>> units_;
   
   int undoCount_;
};