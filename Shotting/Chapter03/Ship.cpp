// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"
#include "CircleComponent.h"
#include "Asteroid.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mLaserCooldown(0.0f)
	, mCircle(nullptr)
{
	// Create a sprite component
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	// Create an input component and set keys/speed
	//変更点
	InputComponent* ic = new InputComponent(this);
	ic->SetRightKey(SDL_SCANCODE_D);
	ic->SetLeftKey(SDL_SCANCODE_A);
	ic->SetJumpKey(SDL_SCANCODE_SPACE);

	ic->SetClockwiseKey(SDL_SCANCODE_Q);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_E);

	//変更点
	ic->SetMaxForwardSpeed(200.0f);
	ic->SetMaxJumpSpeed(100.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi);

	// Create a circle component (for collision)
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(20.0f);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
	//隕石との衝突の判定
	for (auto ast : GetGame()->GetAsteroids())
	{
		if (Intersect(*mCircle, *(ast->GetCircle())))
		{
			// The first asteroid we intersect with,
			// set ourselves and the asteroid to dead
			SetState(EDead);
			ast->SetState(EDead);
			break;
		}
	}
}

void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_RETURN] && mLaserCooldown <= 0.0f)
	{
		// Create a laser and set its position/rotation to mine
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		// Reset laser cooldown (half second)
		mLaserCooldown = 0.5f;
	}
}
