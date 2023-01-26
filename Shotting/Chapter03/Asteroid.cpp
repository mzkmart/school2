#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent2.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

//隕石のスピードと当たり判定の大きさの変更
 float mAsteroidSpeed = 150.0f;
 float mAsteroidRadius = 22.5f;
 //隕石同士の衝突検出のクールタイムめり込み防止
 //衝突後何秒経ったか
 float mCollisionTimer = 0.0f;
 //次の衝突を検出するまでの時間（短くすれば衝突を細かくとるが密集している場合にめり込みやすい）
 float mCollisionCoolTime = 2.5f;
Asteroid::Asteroid(Game* game)
	:Actor(game)
	,mCircle(nullptr)
{
	//隕石をランダムな角度に設定する
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	//spritecomponentの作成
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid2.png"));

	//movecomponentを生成
	MoveComponent2* mc = new MoveComponent2(this);
	//隕石のスピードの設定
	mc->SetForwardSpeed(mAsteroidSpeed);

	//隕石の当たり判定の設定
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(mAsteroidRadius);

	//隕石を配列に格納する
	game->AddAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime)
{
	mCollisionTimer += deltaTime;
	for (auto ast : GetGame()->GetAsteroids())
	{

		//すべての隕石の当たり判定と自分の当たり判定が重なっていないか確認する
		//衝突のクールタイムが経過しているか
		if (mCircle != ast->GetCircle() && mCollisionTimer >= mCollisionCoolTime)
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				float rot = GetRotation();
				if (Math::Pi > ast->GetRotation())
				{
					rot = Math::TwoPi + ast->GetRotation() - 1.5 * Math::Pi - rot;
				}
				else
				{
					rot = -1 * (rot - Math::TwoPi - ast->GetRotation() - 0.5 * Math::Pi);
				}
				SetRotation(rot);
				mCollisionTimer = 0.0f;
			}
		}
	}
}

Asteroid::~Asteroid()
{
	//隕石を削除
	GetGame()->RemoveAsteroid(this);
}
