#pragma once
#include "Actor.h"
class Start : public Actor
{
public:
	Start(class Game* game);
	//���͂��ꂽ�����擾���邽�߂ɐ錾
	void ActorInput(const uint8_t* keyState) override;

};