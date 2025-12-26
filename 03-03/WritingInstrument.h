#pragma once
#include <string>

//==========================
// 筆記用具クラスの宣言
//==========================
class WritingInstrument {
public:
   virtual void Write() = 0;
   virtual ~WritingInstrument() = default;
protected:
   std::string color;
};

//============================
// ボールペンクラスの宣言
//============================
class BallpointPen : public WritingInstrument {
public:
   BallpointPen();
   void Write() override;
};

//==========================
// 鉛筆クラスの宣言
//==========================
class Pencil : public WritingInstrument {
public:
   Pencil();
   void Write() override;
};