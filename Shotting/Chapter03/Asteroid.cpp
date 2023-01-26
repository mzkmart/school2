#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent2.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

//覐΂̃X�s�[�h�Ɠ����蔻��̑傫���̕ύX
 float mAsteroidSpeed = 150.0f;
 float mAsteroidRadius = 22.5f;
 //覐Γ��m�̏Փˌ��o�̃N�[���^�C���߂荞�ݖh�~
 //�Փˌ㉽�b�o������
 float mCollisionTimer = 0.0f;
 //���̏Փ˂����o����܂ł̎��ԁi�Z������ΏՓ˂��ׂ����Ƃ邪���W���Ă���ꍇ�ɂ߂荞�݂₷���j
 float mCollisionCoolTime = 2.5f;
Asteroid::Asteroid(Game* game)
	:Actor(game)
	,mCircle(nullptr)
{
	//覐΂������_���Ȋp�x�ɐݒ肷��
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	//spritecomponent�̍쐬
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid2.png"));

	//movecomponent�𐶐�
	MoveComponent2* mc = new MoveComponent2(this);
	//覐΂̃X�s�[�h�̐ݒ�
	mc->SetForwardSpeed(mAsteroidSpeed);

	//覐΂̓����蔻��̐ݒ�
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(mAsteroidRadius);

	//覐΂�z��Ɋi�[����
	game->AddAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime)
{
	mCollisionTimer += deltaTime;
	for (auto ast : GetGame()->GetAsteroids())
	{

		//���ׂĂ�覐΂̓����蔻��Ǝ����̓����蔻�肪�d�Ȃ��Ă��Ȃ����m�F����
		//�Փ˂̃N�[���^�C�����o�߂��Ă��邩
		if (mCircle != ast->GetCircle() && mCollisionTimer >= mCollisionCoolTime)
		{
			if (Intersect(*mCircle, *(ast->GetCircle())))
			{
				float rot = GetRotation();
				if (Math::Pi > ast->GetRotation())
				{
					rot = Math::TwoPi + ast->GetRotation() - 1.5 * Math::Pi - rot;
				}
				else
				{
					rot = -1 * (rot - Math::TwoPi - ast->GetRotation() - 0.5 * Math::Pi);
				}
				SetRotation(rot);
				mCollisionTimer = 0.0f;
			}
		}
	}
}

Asteroid::~Asteroid()
{
	//覐΂��폜
	GetGame()->RemoveAsteroid(this);
}
