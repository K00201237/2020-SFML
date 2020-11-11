#include "stdafx.h"
#include "PlayableCharacter.h"
#include <iostream>
using namespace std;


void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	// Place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	// Initialize the gravity
	m_Gravity = gravity;

	// Move the sprite in to position
	m_Sprite.setPosition(m_Position);

}

void  PlayableCharacter::moveTo(float elapsedTime, Vector2f playerLocation)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;
	float speed = m_Speed / 2;
	srand(time(0));
	int mod = rand() % 100;
	speed = mod;

	// Update the enemy position variables
	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x +
			speed * elapsedTime;
	}

	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y +
			speed * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x -
			speed * elapsedTime;
	}

	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y -
			speed * elapsedTime;
	}
	// Update the rect for all body parts

	FloatRect r = getPosition();

	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	// Head
	m_Head.left = r.left + 3;
	//m_Head.top = r.top + (r.height * .3);
	m_Head.top = r.top;
	m_Head.width = r.width - 6;
	m_Head.height = 1;

	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .35;
	m_Left.width = 1;
	m_Left.height = r.height * .3;



	m_Sprite.setPosition(m_Position);
}




void PlayableCharacter::update(float elapsedTime)
{

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (m_UpPressed)
	{
		m_Position.y += m_Speed * elapsedTime;
	}

	if (m_DownPressed)
	{
		m_Position.y -= m_Speed * elapsedTime;
	}


	// Handle Jumping
	if (m_IsJumping)
	{
		// Update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		// Is the jump going upwards
		if (m_TimeThisJump < m_JumpDuration)
		{
			// Move up at twice gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}

	}

	// Apply gravity
	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}

	// Update the rect for all body parts
	FloatRect r = getPosition();


	// Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;

	// Head
	m_Head.left = r.left + 3;
	//m_Head.top = r.top + (r.height * .3);
	m_Head.top = r.top;
	m_Head.width = r.width - 6;
	m_Head.height = 1;


	// Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * .35;
	m_Right.width = 1;
	m_Right.height = r.height * .3;

	// Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * .35;
	m_Left.width = 1;
	m_Left.height = r.height * .3;

	// Move the sprite into position
	m_Sprite.setPosition(m_Position);

}

FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2
		);
}

FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}

FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}

FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}



void PlayableCharacter::stopDown(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	
}

void PlayableCharacter::stopUp
(float position)
{
	m_Position.y = position + getPosition().height;
	m_Sprite.setPosition(m_Position);
	
}

void PlayableCharacter::stopRight(float position)
// reduce x by the position - m_Sprite.getGlobalBounds().width;
{
	//cout << "Stop Right m_Position. x was " << m_Position.x;
	//cout << "Stop Right m_Position. y was " << m_Position.y << "\n";
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	//cout << "Stop Right m_Position. x was updated to " << m_Position.x;
	//cout << "Stop Right m_Position. y was updated to " << m_Position.y << "\n";
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position)
// increment x by the width - m_Sprite.getGlobalBounds().width;
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopJump()
{
	// Stop a jump early 
	m_IsJumping = false;
	m_IsFalling = true;
}



