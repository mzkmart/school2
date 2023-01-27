#include "Laser.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Asteroid.h"

//�����̃v���O�����ŃQ�[���̏�Ԃ��m�F�����extern���g�p
extern int mClearFlag;
//���[�U�[�̃X�s�[�h�Ɠ����蔻��̑傫���̕ύX
float mLaserSpaad = 800.0f;
float mLaserRadius = 11.0f;
Laser::Laser(Game* game)
	:Actor(game)
	//��������폜�܂ł̎��Ԃ̐ݒ�
	,mDeathTimer(1.0f)
{
	//spritecomponent�̍쐬
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Laser.png"));

	//movecomponen�̍쐬
	MoveComponent* mc = new MoveComponent(this);
	//���[�U�[�̃X�s�[�h�̐ݒ�
	mc->SetForwardSpeed(mLaserSpaad);

	//���[�U�[�̓����蔻��̐���
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(mLaserRadius);
}

void Laser::UpdateActor(float deltaTime)
{
	//�������Ă��痧�������Ԃ����炷
	mDeathTimer -= deltaTime;
	//�폜�܂ł̎��Ԃ���������
	if (mDeathTimer <= 0.0f)
	{
		//�폜����
		SetState(EDead);
	}
	//�폜���Ȃ������ꍇ��覐΂Ƃ̏Փ˂̊m�F
	else
	{
		for (auto ast : GetGame()->GetAsteroids())
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				//������覐΂̐����L�^
				mClearFlag++;
				//���[�U�[��覐΂��폜����
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}
