#include "MoveComponent.h"
#include "Actor.h"
#include "stdio.h"
#include <iostream>
#include <algorithm>
#include <string>

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
	, mJumpSpeed(0.0f)
	,mJumpForwardSpeed(0.0f)
{

}

void MoveComponent::Update(float deltaTime)
{
	//InputComponent.cppで回転が入力されていたら
	if (!Math::NearZero(mAngularSpeed))
	{
		//現在の回転を取得
		float rot = mOwner->GetRotation();
		//入力された分を足す
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

	//現在のプレイヤーの座標を取得する
	Vector2 pos = mOwner->GetPosition();

	//ジャンプが押されたら
	if (mJumpControl == false)
	{
		//Sin関数を使用し放物線を描くように足す値を入れる
		float jumpValue = Math::Sin(3.14 * mJumpSpeed) * 1.5f;

		//左右に移動中の場合ジャンプしながら左右に動く
		//右に移動中か
		if (mJumpForwardSpeed > 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}
		//左に移動中か
		else if (mJumpForwardSpeed < 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}

		//ジャンプが頂点に達していない
		if (jumpValue <= 0 && mGravityControl == false)
		{
			//Sin関数を使用し放物線を描くようにY座標を足す
			pos.y += jumpValue;
		}
		//ジャンプが頂点に達したので落ちる
		else if (pos.y <= 730.0f)
		{
			//ゆっくりとY座標を下げる
			pos.y += 50 * deltaTime;
			mGravityControl = true;
			mOwner->SetPosition(pos);
			pos = mOwner->GetPosition();
		}
		//ジャンプ後に着地したら
		else if (pos.y > 730.0f)
		{
			//ジャンプのboolをtrueにする
			mJumpControl = true;
			//重力を無効化する
			mGravityControl = false;
			//ジャンプとジャンプ中の横移動の値を０に戻す
			mJumpForwardSpeed = 0.0f;
			mJumpSpeed = 0.0f;
			//下がりすぎた座標を戻す
			pos.y = 730.0f;
			mOwner->SetPosition(pos);
		}

		//ジャンプ量を少しずつ増やす
		mJumpSpeed += 10;
		mOwner->SetPosition(pos);
	}

	//ジャンプ中ではなく横移動入力がされているかどうか
	if (!Math::NearZero(mForwardSpeed) && mJumpControl)
	{
		//現在のプレイヤーの座標を取得しX座標に移動量を足す
		pos = mOwner->GetPosition();
		pos.x += mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}

	//プレイヤーが左に移動し画面端に行った場合右端に移動する
	if (pos.x < 0.0f) 
	{ 
		pos.x = 1022.0f; 
	}
	//プレイヤーが右に移動し画面端に行った場合左端に移動する
	else if (pos.x > 1024.0f) 
	{ 
		pos.x = 2.0f; 
	}

	mOwner->SetPosition(pos);
}
