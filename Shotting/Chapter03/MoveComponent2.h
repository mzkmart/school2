#pragma once
#include "Component.h"

class MoveComponent2 : public Component
{
public:
	MoveComponent2(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	//Asteroid.cppとLaser.cppで別々に設定するためのメソッド
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	//進む量を入れる変数
	float mForwardSpeed;
};
