// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
:Component(owner, updateOrder)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
,mJumpSpeed(0.0f)
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

	
	//変更点
	Vector2 pos = mOwner->GetPosition();
	if (pos.y < 768.0f)
	{ 
		pos.y += 300 * deltaTime;
		mOwner->SetPosition(pos);
	}
	else if (pos.y >= 768.0f)
	{
		mJumptime = 0.0f;
		mControl = 0;
	}

	if (!Math::NearZero(mJumpSpeed) && mControl < 3)
	{
		mControl = 3;
		mJumpForwardSpeed = mForwardSpeed;
	}

	if (mJumptime > 0.5f)
	{
		pos.x += mJumpForwardSpeed * deltaTime;
		mControl = 4;
		mJumpSpeed = 0.0f;
	}
	else if (mJumptime <= 0.5f && mControl == 3)
	{
		pos = mOwner->GetPosition();
		pos.y -= mJumpSpeed * deltaTime;
		mJumptime += deltaTime;
		pos.x += mJumpForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}
	

	if (!Math::NearZero(mForwardSpeed) && mControl < 3)
	{
		//変更点
		pos = mOwner->GetPosition();
		pos.x += mForwardSpeed * deltaTime;
	}
	// (Screen wrapping code only for asteroids)
	if (pos.x < 0.0f) { pos.x = 1022.0f; }
	else if (pos.x > 1024.0f) { pos.x = 2.0f; }

	if (pos.y < 0.0f) { pos.y = 2.0f; }
	else if (pos.y > 768.0f) { pos.y = 768.0f; }

	mOwner->SetPosition(pos);
}
