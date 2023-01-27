#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(class Game* game);
	~Asteroid();
	//覐΂̓����蔻��̎擾
	class CircleComponent* GetCircle() { return mCircle; }
	void UpdateActor(float deltaTime) override;
private:
	//覐΂̓����蔻��̐���
	class CircleComponent* mCircle;
};
