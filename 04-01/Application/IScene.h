#pragma once

enum SCENE {
   TITLE,
   STAGE,
   CLEAR
};

class IScene {
public:
   IScene();
   virtual ~IScene() = default;

   virtual void Update() = 0;
   virtual void Draw() = 0;

   static SCENE GetSceneType();

protected:
   static SCENE sceneType_;
};