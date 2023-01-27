#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
:PlayerMove(owner)
,mRightKey(0)
,mLeftKey(0)
,mJumpKey(0)
,mClockwiseKey(0)
,mCounterClockwiseKey(0)
{
	
}

//�ǂ̃L�[�������ꂽ�̂����擾
void InputComponent::ProcessInput(const uint8_t* keyState)
{
	//�L�[��������Ȃ������ꍇ�͂O�����邽�߂O����Ă���
	float forwardSpeed = 0.0f;

	//Ship.cpp��Ship::Ship(Game* game):Actor(game)�Őݒ肵���L�[��������Ă��邩���m�F����
	if (keyState[mRightKey])
	{
		//�E�ɐi�߂邽�߂�forwardSpeed�ɑ���
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mLeftKey])
	{
		//���ɐi�߂邽�߂�forwardSpeed�������
		forwardSpeed -= mMaxForwardSpeed;
		//���E��������Ă�ꍇ�͓����l�𑫂���������̂�0�ɂȂ�ς��Ȃ�
	}
	//�W�����v�o�����ԂŃL�[�������ꂽ��
	if (keyState[mJumpKey] && GetJumpBool())
	{
		//�W�����v���o���Ȃ��悤��Jumpflag��false�ɂ���
		SetJumpflag(false);
		//���Ɉړ����̏ꍇ�̓W�����v���Ɉړ�����悤�ɐݒ肷��
		SetJumpForward(forwardSpeed);
	}

	//�L�[��������Ȃ������ꍇ�͂O�����邽�߂O����Ă���
	float angularSpeed = 0.0f;
	//Ship.cpp��Ship::Ship(Game* game):Actor(game)�Őݒ肵���L�[��������Ă��邩���m�F����
	if (keyState[mClockwiseKey])
	{
		//�E�ɉ�]���邽�߂�angularSpeed�ɑ���
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey])
	{
		//���ɉ�]���邽�߂�angularSpeed�������
		angularSpeed -= mMaxAngularSpeed;
		//���E��������Ă�ꍇ�͓����l�𑫂���������̂�0�ɂȂ�ς��Ȃ�
	}
	//PlayerMove.cpp�ɐ��l��n��
	SetAngularSpeed(angularSpeed);
	SetForwardSpeed(forwardSpeed);

}
