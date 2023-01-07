#include "MoveComponent.h"
#include "Actor.h"
#include "stdio.h"
#include <iostream>
#include <algorithm>
#include <string>

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
	, mJumpSpeed(0.0f)
	,mJumpForwardSpeed(0.0f)
{

}

void MoveComponent::Update(float deltaTime)
{
	//InputComponent.cpp�ŉ�]�����͂���Ă�����
	if (!Math::NearZero(mAngularSpeed))
	{
		//���݂̉�]���擾
		float rot = mOwner->GetRotation();
		//���͂��ꂽ���𑫂�
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

	//���݂̃v���C���[�̍��W���擾����
	Vector2 pos = mOwner->GetPosition();

	//�W�����v�������ꂽ��
	if (mJumpControl == false)
	{
		//Sin�֐����g�p����������`���悤�ɑ����l������
		float jumpValue = Math::Sin(3.14 * mJumpSpeed) * 1.5f;

		//���E�Ɉړ����̏ꍇ�W�����v���Ȃ��獶�E�ɓ���
		//�E�Ɉړ�����
		if (mJumpForwardSpeed > 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}
		//���Ɉړ�����
		else if (mJumpForwardSpeed < 0)
		{
			pos.x -= Math::Sin(3.14 * mJumpForwardSpeed);
		}

		//�W�����v�����_�ɒB���Ă��Ȃ�
		if (jumpValue <= 0 && mGravityControl == false)
		{
			//Sin�֐����g�p����������`���悤��Y���W�𑫂�
			pos.y += jumpValue;
		}
		//�W�����v�����_�ɒB�����̂ŗ�����
		else if (pos.y <= 730.0f)
		{
			//��������Y���W��������
			pos.y += 50 * deltaTime;
			mGravityControl = true;
			mOwner->SetPosition(pos);
			pos = mOwner->GetPosition();
		}
		//�W�����v��ɒ��n������
		else if (pos.y > 730.0f)
		{
			//�W�����v��bool��true�ɂ���
			mJumpControl = true;
			//�d�͂𖳌�������
			mGravityControl = false;
			//�W�����v�ƃW�����v���̉��ړ��̒l���O�ɖ߂�
			mJumpForwardSpeed = 0.0f;
			mJumpSpeed = 0.0f;
			//�����肷�������W��߂�
			pos.y = 730.0f;
			mOwner->SetPosition(pos);
		}

		//�W�����v�ʂ����������₷
		mJumpSpeed += 10;
		mOwner->SetPosition(pos);
	}

	//�W�����v���ł͂Ȃ����ړ����͂�����Ă��邩�ǂ���
	if (!Math::NearZero(mForwardSpeed) && mJumpControl)
	{
		//���݂̃v���C���[�̍��W���擾��X���W�Ɉړ��ʂ𑫂�
		pos = mOwner->GetPosition();
		pos.x += mForwardSpeed * deltaTime;
		mOwner->SetPosition(pos);
	}

	//�v���C���[�����Ɉړ�����ʒ[�ɍs�����ꍇ�E�[�Ɉړ�����
	if (pos.x < 0.0f) 
	{ 
		pos.x = 1022.0f; 
	}
	//�v���C���[���E�Ɉړ�����ʒ[�ɍs�����ꍇ���[�Ɉړ�����
	else if (pos.x > 1024.0f) 
	{ 
		pos.x = 2.0f; 
	}

	mOwner->SetPosition(pos);
}
