#include "MoveComponent2.h"
#include "Actor.h"

MoveComponent2::MoveComponent2(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mForwardSpeed(0.0f)
{

}

//���[�U�[��覐΂͌����Ă�����ɐi�ݑ�����
void MoveComponent2::Update(float deltaTime)
{
	//���W���擾�������Ă�����ɒl�𑫂�
	Vector2 pos = mOwner->GetPosition();
	//mForwardSpeed��Asteroid.cpp��Laser.cpp�ŕʁX�ɐݒ�ς�
	pos += mOwner->GetForward() * mForwardSpeed * deltaTime;

	//���Ɉړ�����ʒ[�ɍs�����ꍇ�E�[�Ɉړ�����
	if (pos.x < 0.0f) 
	{ 
		pos.x = 1022.0f; 
	}
	//�E�Ɉړ�����ʒ[�ɍs�����ꍇ���[�Ɉړ�����
	else if (pos.x > 1024.0f) 
	{ 
		pos.x = 2.0f; 
	}

	//�����Ă�������擾���㉺�̉�ʔ����ɍs�����ۂɕ����]����������
	float rot = mOwner->GetRotation();
	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
		rot = TwoPi - rot;
	}
	else if (pos.y > 768.0f)
	{
		pos.y = 768.0f;
		rot = -1 * (rot - TwoPi);
	}

	mOwner->SetPosition(pos);
	mOwner->SetRotation(rot);
}
