#pragma once
#include "Actor.h"
class Start : public Actor
{
public:
	Start(class Game* game);
	//入力されたかを取得するために宣言
	void ActorInput(const uint8_t* keyState) override;

};