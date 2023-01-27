#include "Laser.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Asteroid.h"

//複数のプログラムでゲームの状態を確認する為externを使用
extern int mClearFlag;
//レーザーのスピードと当たり判定の大きさの変更
float mLaserSpaad = 800.0f;
float mLaserRadius = 11.0f;
Laser::Laser(Game* game)
	:Actor(game)
	//生成から削除までの時間の設定
	,mDeathTimer(1.0f)
{
	//spritecomponentの作成
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Laser.png"));

	//movecomponenの作成
	MoveComponent* mc = new MoveComponent(this);
	//レーザーのスピードの設定
	mc->SetForwardSpeed(mLaserSpaad);

	//レーザーの当たり判定の生成
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(mLaserRadius);
}

void Laser::UpdateActor(float deltaTime)
{
	//生成してから立った時間を減らす
	mDeathTimer -= deltaTime;
	//削除までの時間がたったか
	if (mDeathTimer <= 0.0f)
	{
		//削除する
		SetState(EDead);
	}
	//削除しなかった場合は隕石との衝突の確認
	else
	{
		for (auto ast : GetGame()->GetAsteroids())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				//消した隕石の数を記録
				mClearFlag++;
				//レーザーと隕石を削除する
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}
