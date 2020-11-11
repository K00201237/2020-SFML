#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/player.png"));

	m_JumpDuration = .25;
}

bool Bob::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		m_UpPressed = true;

	}
	else
	{
		m_UpPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		m_DownPressed = true;

	}
	else
	{
		m_DownPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;

	}
	else
	{
		m_LeftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::Right))
	{

		m_RightPressed = true;;

	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}