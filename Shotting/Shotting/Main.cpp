//Loopをさせるメインプログラム
#include "Game.h"
#include "Start.h"

//複数のプログラムでゲームの状態を確認する為externを使用
extern int mStartFlag;

int main(int argc, char** argv)
{
	Game game;
	//gameのスタート画面を表示させるメソッドが成功したかを取得
	bool success = game.Initialize2();
	//画面が正しく動いた場合Loopに入る
	if (success)
	{
		game.RunLoop();
	}
	//正しく表示出来なかった場合は秀りゅおうする
	game.Shutdown();
	return 0;
}
