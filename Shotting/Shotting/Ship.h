#pragma once
#include "Actor.h"
class Ship : public Actor
{
public:
	Ship(class Game* game);

	//プレイヤーのUpdate
	void UpdateActor(float deltaTime) override;
	//プレイヤーの入力確認
	void ActorInput(const uint8_t* keyState) override;
private:
	//レーザーのクールタイム
	float mLaserCooldown;
	//プレイヤーの当たり判定
	class CircleComponent* mCircle;
};