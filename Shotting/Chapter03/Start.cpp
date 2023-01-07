#include "Start.h"
#include "InputComponent.h"
#include "Game.h"

//複数のプログラムでゲームの状態を確認する為externを使用
extern int mStartFlag;

Start::Start(Game* game)
	:Actor(game)
{
}

//スタート、ゲームオーバー、クリア画面で入力されたか
void Start::ActorInput(const uint8_t* keyState)
{
	//Sキーが押されたら
	if (keyState[SDL_SCANCODE_S])
	{
		//mStartFlagを1にすることでゲームがスタートする
		mStartFlag = 1;
	}
}
