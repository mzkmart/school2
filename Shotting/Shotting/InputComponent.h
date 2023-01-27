#pragma once
#include "PlayerMove.h"
#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public PlayerMove
{
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const uint8_t* keyState) override;

	//Ship.cppで移動量の数値設定するために使用する
	//横に進む量の設定
	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	//回転する量の設定
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	//ジャンプする量の設定
	void SetMaxJumpSpeed(float speed) { mMaxJumpSpeed = speed; }


	//Ship.cppでキーを設定するために使用する
	//右移動のキーの設定
	void SetRightKey(int key) { mRightKey = key; }
	//左移動のキーの設定
	void SetLeftKey(int key) { mLeftKey = key; }
	//ジャンプキーの設定
	void SetJumpKey(int key) { mJumpKey = key; }
	//右回転のキー設定
	void SetClockwiseKey(int key) { mClockwiseKey = key; }
	//左回転のキー設定
	void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }

private:
	//横移動量
	float mMaxForwardSpeed;
	//回転量
	float mMaxAngularSpeed;
	//ジャンプ量
	float mMaxJumpSpeed;
	//右移動キー
	int mRightKey;
	//左移動キー
	int mLeftKey;
	//右回転キー
	int mRightRotateKey;
	//左回転キー
	int mLeftRotateKey;
	//ジャンプキー
	int mJumpKey;
	//右回転キー
	int mClockwiseKey;
	//左回転キー
	int mCounterClockwiseKey;
};
