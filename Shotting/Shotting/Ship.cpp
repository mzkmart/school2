#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"
#include "CircleComponent.h"
#include "Asteroid.h"

//複数のプログラムでゲームの状態を確認する為externを使用
extern int mStartFlag;

Ship::Ship(Game* game)
	:Actor(game)
	,mLaserCooldown(0.0f)
	, mCircle(nullptr)
{
	//sprite componentの作成
	SpriteComponent* sc = new SpriteComponent(this, 150);
	//画像の指定
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	//キーを指定する
	InputComponent* ic = new InputComponent(this);
	ic->SetRightKey(SDL_SCANCODE_D);
	ic->SetLeftKey(SDL_SCANCODE_A);
	ic->SetJumpKey(SDL_SCANCODE_SPACE);

	ic->SetClockwiseKey(SDL_SCANCODE_Q);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_E);

	//プレイヤーの速度を指定
	ic->SetMaxForwardSpeed(200.0f);
	ic->SetMaxJumpSpeed(100.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi);

	//プレイヤーの当たり判定を作成
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(20.0f);
}

//プレイヤーが隕石とぶつかったかの判定
void Ship::UpdateActor(float deltaTime)
{
	//レーザーのクールタイムを計測する
	mLaserCooldown -= deltaTime;
	//隕石との衝突の判定
	for (auto ast : GetGame()->GetAsteroids())
	{
		//すべての隕石の当たり判定と自分の当たり判定が重なっていないか確認する
		if (Intersect(*mCircle, *(ast->GetCircle())))
		{
			//プレーヤーを消す。
			SetState(EDead);
			//mStartFlagを４にしゲームオーバー画面を生成する
			mStartFlag = 4;
			break;
		}
	}
}

//レーザーを発射
void Ship::ActorInput(const uint8_t* keyState)
{
	//Enterが押されて、クールタイムが上がっていたらレーザーを打つ
	if (keyState[SDL_SCANCODE_RETURN] && mLaserCooldown <= 0.0f)
	{
		//レーザーをプレイヤーの位置と角度に合わせて生成
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		//クールタイムの設定
		mLaserCooldown = 0.5f;
	}
}
