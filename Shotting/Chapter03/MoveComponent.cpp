// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

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
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

	Vector2 pos = mOwner->GetPosition();

	if (mJumpControl == false)
	{
		float a = Math::Sin(3.14 * mJumpSpeed) * 1.5f;
		if (mJumpForwardSpeed > 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}
		else if (mJumpForwardSpeed < 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}

		if (a <= 0 && mGravityControl == false)
		{
			pos.y += a;
		}
		else if (pos.y <= 730.0f)
		{
			pos.y += 50 * deltaTime;
			mGravityControl = true;
			mOwner->SetPosition(pos);
			pos = mOwner->GetPosition();
		}
		else if (pos.y > 730.0f)
		{
			mJumpControl = true;
			mGravityControl = false;
			mJumpForwardSpeed = 0.0f;
			pos.y = 730.0f;
			mJumpSpeed = 0.0f;
			printf("%f\n", pos.y);
			mOwner->SetPosition(pos);
		}

		mJumpSpeed += 10;
		mOwner->SetPosition(pos);
	}

	if (!Math::NearZero(mForwardSpeed) && mJumpControl)
	{
		pos = mOwner->GetPosition();
		pos.x += mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}
	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f) { pos.x = 1022.0f; }
	else if (pos.x > 1024.0f) { pos.x = 2.0f; }

	mOwner->SetPosition(pos);
}
