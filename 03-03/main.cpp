#include "WritingInstrument.h"
#include <memory>

int main() {
   // WritingInstrumentクラスのポインタ配列を作成
	std::unique_ptr<WritingInstrument> instruments[2];
	
	// ボールペンと鉛筆のインスタンスを作成して配列に格納
	instruments[0] = std::make_unique<BallpointPen>();
	instruments[1] = std::make_unique<Pencil>();
	
	// 各筆記用具で書く動作を実行
	for (const auto& instrument : instruments) {
		instrument->Write();
	}

   return 0;
}