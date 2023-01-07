#include "Asteroid.h"
#include "SpriteComponent.h"
#include "MoveComponent2.h"
#include "Game.h"
#include "Random.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* game)
	:Actor(game)
	,mCircle(nullptr)
{
	//覐΂������_���Ȉʒu�A�p�x�ɐݒ肷��
	//�������Ƀv���C���[�Ɠ�����Ȃ��悤�ɒ���
	Vector2 randPos = Random::GetVector(Vector2::Zero,
		Vector2(1024.0f, 500.0f));
	SetPosition(randPos);

	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	//spritecomponent�̍쐬
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid2.png"));

	//movecomponent�𐶐�
	MoveComponent2* mc = new MoveComponent2(this);
	//覐΂̃X�s�[�h�̐ݒ�
	mc->SetForwardSpeed(150.0f);

	//覐΂̓����蔻��̐ݒ�
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(20.0f);

	//覐΂�z��Ɋi�[����
	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	//覐΂��폜
	GetGame()->RemoveAsteroid(this);
}
