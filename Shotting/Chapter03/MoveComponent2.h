#pragma once
#include "Component.h"

class MoveComponent2 : public Component
{
public:
	MoveComponent2(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	//Asteroid.cpp��Laser.cpp�ŕʁX�ɐݒ肷�邽�߂̃��\�b�h
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	//�i�ޗʂ�����ϐ�
	float mForwardSpeed;
};
