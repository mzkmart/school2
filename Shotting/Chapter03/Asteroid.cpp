#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent2.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* game)
	:Actor(game)
	,mCircle(nullptr)
{
	//隕石をランダムな位置、角度に設定する
	//生成時にプレイヤーと当たらないように調整
	Vector2 randPos = Random::GetVector(Vector2::Zero,
		Vector2(1024.0f, 500.0f));
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	//spritecomponentの作成
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid2.png"));

	//movecomponentを生成
	MoveComponent2* mc = new MoveComponent2(this);
	//隕石のスピードの設定
	mc->SetForwardSpeed(150.0f);

	//隕石の当たり判定の設定
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(20.0f);

	//隕石を配列に格納する
	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	//隕石を削除
	GetGame()->RemoveAsteroid(this);
}
