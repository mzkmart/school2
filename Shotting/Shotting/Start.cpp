#include "Start.h"
#include "InputComponent.h"
#include "Game.h"

//�����̃v���O�����ŃQ�[���̏�Ԃ��m�F�����extern���g�p
extern int mStartFlag;

Start::Start(Game* game)
	:Actor(game)
{
}

//�X�^�[�g�A�Q�[���I�[�o�[�A�N���A��ʂœ��͂��ꂽ��
void Start::ActorInput(const uint8_t* keyState)
{
	//S�L�[�������ꂽ��
	if (keyState[SDL_SCANCODE_S])
	{
		//mStartFlag��1�ɂ��邱�ƂŃQ�[�����X�^�[�g����
		mStartFlag = 1;
	}
}
