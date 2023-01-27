#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:PlayerMove(owner)
,mRightKey(0)
,mLeftKey(0)
,mJumpKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
	
}

//どのキーが押されたのかを取得
void InputComponent::ProcessInput(const uint8_t* keyState)
{
	//キーが押されなかった場合は０を入れるため０入れておく
	float forwardSpeed = 0.0f;

	//Ship.cppのShip::Ship(Game* game):Actor(game)で設定したキーが押されているかを確認する
	if (keyState[mRightKey])
	{
		//右に進めるためにforwardSpeedに足す
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mLeftKey])
	{
		//左に進めるためにforwardSpeedから引く
		forwardSpeed -= mMaxForwardSpeed;
		//左右が押されてる場合は同じ値を足し引きするので0になり変わらない
	}
	//ジャンプ出来る状態でキーが押されたか
	if (keyState[mJumpKey] && GetJumpBool())
	{
		//ジャンプを出来ないようにJumpflagをfalseにする
		SetJumpflag(false);
		//横に移動中の場合はジャンプ中に移動するように設定する
		SetJumpForward(forwardSpeed);
	}

	//キーが押されなかった場合は０を入れるため０入れておく
	float angularSpeed = 0.0f;
	//Ship.cppのShip::Ship(Game* game):Actor(game)で設定したキーが押されているかを確認する
	if (keyState[mClockwiseKey])
	{
		//右に回転するためにangularSpeedに足す
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey])
	{
		//左に回転するためにangularSpeedから引く
		angularSpeed -= mMaxAngularSpeed;
		//左右が押されてる場合は同じ値を足し引きするので0になり変わらない
	}
	//PlayerMove.cppに数値を渡す
	SetAngularSpeed(angularSpeed);
	SetForwardSpeed(forwardSpeed);

}
