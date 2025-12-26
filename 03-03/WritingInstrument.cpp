#include "WritingInstrument.h"
#include <iostream>

//============================
// ボールペンクラスのメソッド定義
//============================
BallpointPen::BallpointPen() {
   color = "Blue";
}

void BallpointPen::Write() {
   std::cout << "Writing with a " << color << " ballpoint pen." << std::endl;
}

//==========================
// 鉛筆クラスのメソッド定義
//==========================
Pencil::Pencil() {
   color = "Gray";
}

void Pencil::Write() {
   std::cout << "Writing with a " << color << " pencil." << std::endl;
}
