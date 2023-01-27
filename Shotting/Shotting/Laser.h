#pragma once
#include "Actor.h"
class Laser : public Actor
{
public:
	Laser(class Game* game);
	//���[�U�[��Update
	void UpdateActor(float deltaTime) override;
private:
	//���[�U�[�̓����蔻��
	class CircleComponent* mCircle;
	//���[�U�[�̍폜�܂ł̎���
	float mDeathTimer;
};
