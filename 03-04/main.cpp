#include "Shape.h"
#include <memory>

int main() {
   // Shapeクラスのポインタ配列を作成
	std::unique_ptr<IShape> shapes[2];

	// CircleとRectangleのインスタンスを作成して配列に格納
	shapes[0] = std::make_unique<Circle>(5.0f);
	shapes[1] = std::make_unique<Rectangle>(4.0f, 6.0f);

	// 各図形のサイズ計算と描画を実行
	for (const auto& shape : shapes) {
		shape->Size();
		shape->Draw();
	}

   return 0;
}