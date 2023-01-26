#include "MoveComponent2.h"
#include "Actor.h"

MoveComponent2::MoveComponent2(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mForwardSpeed(0.0f)
{

}

//レーザーと隕石は向いてる方向に進み続ける
void MoveComponent2::Update(float deltaTime)
{
	//座標を取得し向いてる方向に値を足す
	Vector2 pos = mOwner->GetPosition();
	//mForwardSpeedはAsteroid.cppとLaser.cppで別々に設定済み
	pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

	//左に移動し画面端に行った場合右端に移動する
	if (pos.x < 0.0f) 
	{ 
		pos.x = 1022.0f; 
	}
	//右に移動し画面端に行った場合左端に移動する
	else if (pos.x > 1024.0f) 
	{ 
		pos.x = 2.0f; 
	}

	//向いてる方向を取得し上下の画面買いに行った際に方向転換をさせる
	float rot = mOwner->GetRotation();
	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
		rot = TwoPi - rot;
	}
	else if (pos.y > 768.0f)
	{
		pos.y = 768.0f;
		rot = -1 * (rot - TwoPi);
	}

	mOwner->SetPosition(pos);
	mOwner->SetRotation(rot);
}
