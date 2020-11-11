#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/tom.png"));

	m_JumpDuration = .45;
}

// A virtual function
bool Thomas::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		m_UpPressed = true;

	}
	else
	{
		m_UpPressed = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		m_DownPressed = true;

	}
	else
	{
		m_DownPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}


	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}