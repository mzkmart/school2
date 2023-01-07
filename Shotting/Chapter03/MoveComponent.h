#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;
	
	//InputComponent.cpp�ŃW�����v�ł��邩�̔�����擾���郁�\�b�h
	float GetJumpBool() const { return mJumpControl; }

	//InputComponent.cpp�œ��͂��ꂽ���l�����郁�\�b�h
	//��]�̐��l������
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	//���ړ��̐��l������
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	//�W�����v�̐��l������
	void SetJumpSpeed(float speed) { mJumpSpeed = speed; }
	//�W�����v���̉��ړ��̐��l������
	void SetJumpForward(float speed) { mJumpForwardSpeed = speed; }
	//�W�����v�̃t���O��ύX����
	void SetJumpflag(bool flag) { mJumpControl = flag; }
private:
	//��]����l
	float mAngularSpeed;
	//���ړ��̒l
	float mForwardSpeed;
	//�W�����v�̒l
	float mJumpSpeed;
	//�W�����v���̉��ړ��̒l
	float mJumpForwardSpeed;
	//�W�����v�̃t���O
	bool mJumpControl = true;
	//�d�͂������邩�̃t���O
	bool mGravityControl = false;
};
