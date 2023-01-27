#pragma once
#include "Actor.h"
class Start : public Actor
{
public:
	Start(class Game* game);
	//“ü—Í‚³‚ê‚½‚©‚ğæ“¾‚·‚é‚½‚ß‚ÉéŒ¾
	void ActorInput(const uint8_t* keyState) override;

};