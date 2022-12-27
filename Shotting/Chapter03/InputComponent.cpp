// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:MoveComponent(owner)
,mRightKey(0)
,mLeftKey(0)
//ïœçXì_
,mJumpKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
	
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	// Calculate forward speed for MoveComponent
	float forwardSpeed = 0.0f;
	if (keyState[mRightKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mLeftKey])
	{
		forwardSpeed -= mMaxForwardSpeed;
	}
	if (keyState[mJumpKey] && GetJumpBool())
	{
		SetJumpflag(false);
		SetJumpForward(forwardSpeed);
	}
	SetForwardSpeed(forwardSpeed);

}
