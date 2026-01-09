#pragma once
class IStageSceneCommand {
public:
   virtual ~IStageSceneCommand() = default;
   virtual void Execute() = 0;
};