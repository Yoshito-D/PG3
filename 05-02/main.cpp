#include <Novice.h>
#include "Application/GameManager.h"

const char kWindowTitle[] = "LE2A_20_ヨシト_ダイキ_05-02";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

   // ライブラリの初期化
   Novice::Initialize(kWindowTitle, 1280, 720);

   GameManager gameManager;

   gameManager.Run();

   // ライブラリの終了
   Novice::Finalize();
   return 0;
}
