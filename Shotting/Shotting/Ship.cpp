#include "Ship.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "Game.h"
#include "Laser.h"
#include "CircleComponent.h"
#include "Asteroid.h"

//�����̃v���O�����ŃQ�[���̏�Ԃ��m�F�����extern���g�p
extern int mStartFlag;

Ship::Ship(Game* game)
	:Actor(game)
	,mLaserCooldown(0.0f)
	, mCircle(nullptr)
{
	//sprite component�̍쐬
	SpriteComponent* sc = new SpriteComponent(this, 150);
	//�摜�̎w��
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	//�L�[���w�肷��
	InputComponent* ic = new InputComponent(this);
	ic->SetRightKey(SDL_SCANCODE_D);
	ic->SetLeftKey(SDL_SCANCODE_A);
	ic->SetJumpKey(SDL_SCANCODE_SPACE);

	ic->SetClockwiseKey(SDL_SCANCODE_Q);
	ic->SetCounterClockwiseKey(SDL_SCANCODE_E);

	//�v���C���[�̑��x���w��
	ic->SetMaxForwardSpeed(200.0f);
	ic->SetMaxJumpSpeed(100.0f);
	ic->SetMaxAngularSpeed(Math::TwoPi);

	//�v���C���[�̓����蔻����쐬
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(20.0f);
}

//�v���C���[��覐΂ƂԂ��������̔���
void Ship::UpdateActor(float deltaTime)
{
	//���[�U�[�̃N�[���^�C�����v������
	mLaserCooldown -= deltaTime;
	//覐΂Ƃ̏Փ˂̔���
	for (auto ast : GetGame()->GetAsteroids())
	{
		//���ׂĂ�覐΂̓����蔻��Ǝ����̓����蔻�肪�d�Ȃ��Ă��Ȃ����m�F����
		if (Intersect(*mCircle, *(ast->GetCircle())))
		{
			//�v���[���[�������B
			SetState(EDead);
			//mStartFlag���S�ɂ��Q�[���I�[�o�[��ʂ𐶐�����
			mStartFlag = 4;
			break;
		}
	}
}

//���[�U�[�𔭎�
void Ship::ActorInput(const uint8_t* keyState)
{
	//Enter��������āA�N�[���^�C�����オ���Ă����烌�[�U�[��ł�
	if (keyState[SDL_SCANCODE_RETURN] && mLaserCooldown <= 0.0f)
	{
		//���[�U�[���v���C���[�̈ʒu�Ɗp�x�ɍ��킹�Đ���
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		//�N�[���^�C���̐ݒ�
		mLaserCooldown = 0.5f;
	}
}
