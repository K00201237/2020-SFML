#include "stdafx.h"
#include "PlayerChar.h"
#include "TextureHolder.h"

PlayerChar::PlayerChar()
{
	// Associate a texture with the sprite
	p_sprite = Sprite(TextureHolder::GetTexture(
		"graphics/player_idle.png"));

	p_jumpDuration = .45;
}

bool PlayerChar::handleInput()
{
	p_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{

		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!p_isJumping && !p_isFalling)
		{
			p_isJumping = true;
			p_timeThisJump = 0;
			p_justJumped = true;
		}
	}
	else
	{
		p_isJumping = false;
		p_isFalling = true;

	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		p_leftPressed = true;
	}
	else
	{
		p_leftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		p_rightPressed = true;
	}
	else
	{
		p_rightPressed = false;
	}

	return p_justJumped;
}
