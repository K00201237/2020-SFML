#pragma once
#include "Player.h"

class PlayerChar : public Player
{
public:
	// A constructor specific to playable character
	PlayerChar::PlayerChar();

	// The overriden input handler for Thomas
	bool virtual handleInput();

};