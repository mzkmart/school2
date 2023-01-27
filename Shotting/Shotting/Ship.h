#pragma once
#include "Actor.h"
class Ship : public Actor
{
public:
	Ship(class Game* game);

	//�v���C���[��Update
	void UpdateActor(float deltaTime) override;
	//�v���C���[�̓��͊m�F
	void ActorInput(const uint8_t* keyState) override;
private:
	//���[�U�[�̃N�[���^�C��
	float mLaserCooldown;
	//�v���C���[�̓����蔻��
	class CircleComponent* mCircle;
};