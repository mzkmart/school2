#pragma once
#include "Actor.h"
class Laser : public Actor
{
public:
	Laser(class Game* game);
	//レーザーのUpdate
	void UpdateActor(float deltaTime) override;
private:
	//レーザーの当たり判定
	class CircleComponent* mCircle;
	//レーザーの削除までの時間
	float mDeathTimer;
};
