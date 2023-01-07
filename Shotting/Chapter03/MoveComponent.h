#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;
	
	//InputComponent.cppでジャンプできるかの判定を取得するメソッド
	float GetJumpBool() const { return mJumpControl; }

	//InputComponent.cppで入力された時値を入れるメソッド
	//回転の数値を入れる
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	//横移動の数値を入れる
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	//ジャンプの数値を入れる
	void SetJumpSpeed(float speed) { mJumpSpeed = speed; }
	//ジャンプ中の横移動の数値を入れる
	void SetJumpForward(float speed) { mJumpForwardSpeed = speed; }
	//ジャンプのフラグを変更する
	void SetJumpflag(bool flag) { mJumpControl = flag; }
private:
	//回転する値
	float mAngularSpeed;
	//横移動の値
	float mForwardSpeed;
	//ジャンプの値
	float mJumpSpeed;
	//ジャンプ時の横移動の値
	float mJumpForwardSpeed;
	//ジャンプのフラグ
	bool mJumpControl = true;
	//重力をかけるかのフラグ
	bool mGravityControl = false;
};
