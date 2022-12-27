// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	// Lower update order to update first
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;
	
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	float GetJumpBool() const { return mJumpControl; }
	//変更点
	float GetJumpSpeed() const { return mJumpSpeed;  }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	void SetJumpSpeed(float speed) { mJumpSpeed = speed; }
	void SetJumpForward(float speed) { mJumpForwardSpeed = speed; }
	void SetJumpflag(bool flag) { mJumpControl = flag; }
private:
	// Controls rotation (radians/second)
	float mAngularSpeed;
	// Controls forward movement (units/second)
	float mForwardSpeed;
	//変更点
	float mJumpSpeed;
	float mJumptime;
	bool mJumpBool = false;
	bool mJumpControl = true;
	bool mGravityControl = false;
	float mJumpForwardSpeed;
};
