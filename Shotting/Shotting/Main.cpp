//Loop�������郁�C���v���O����
#include "Game.h"
#include "Start.h"

//�����̃v���O�����ŃQ�[���̏�Ԃ��m�F�����extern���g�p
extern int mStartFlag;

int main(int argc, char** argv)
{
	Game game;
	//game�̃X�^�[�g��ʂ�\�������郁�\�b�h���������������擾
	bool success = game.Initialize2();
	//��ʂ��������������ꍇLoop�ɓ���
	if (success)
	{
		game.RunLoop();
	}
	//�������\���o���Ȃ������ꍇ�͏G��エ������
	game.Shutdown();
	return 0;
}
