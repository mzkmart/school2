#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	//Asteroid.cppとLaser.cppで別々に設定するためのメソッド
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	//進む量を入れる変数
	float mForwardSpeed;
	//円周率　回転に使用
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
};
