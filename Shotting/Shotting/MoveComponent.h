#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	//Asteroid.cpp��Laser.cpp�ŕʁX�ɐݒ肷�邽�߂̃��\�b�h
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	//�i�ޗʂ�����ϐ�
	float mForwardSpeed;
	//�~�����@��]�Ɏg�p
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
};
