#pragma once
#include "Actor.h"
class Asteroid : public Actor
{
public:
	Asteroid(class Game* game);
	~Asteroid();
	//è¦Î‚Ì“–‚½‚è”»’è‚Ìæ“¾
	class CircleComponent* GetCircle() { return mCircle; }
	void UpdateActor(float deltaTime) override;
private:
	//è¦Î‚Ì“–‚½‚è”»’è‚Ì¶¬
	class CircleComponent* mCircle;
};
