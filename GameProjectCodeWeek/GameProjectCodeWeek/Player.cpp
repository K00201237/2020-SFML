#include "stdafx.h"
#include "Player.h"

void Player::spawn(Vector2f startPosition, float gravity)
{
	p_position.x = startPosition.x;
	p_position.y = startPosition.y;

	p_sprite.setPosition(p_position);

	p_gravity = gravity;
}

FloatRect Player::getPosition()
{
	return p_sprite.getGlobalBounds();
}

FloatRect Player::getHead()
{
	return p_head;
}

FloatRect Player::getFeet()
{
	return p_feet;
}

FloatRect Player::getRight()
{
	return p_right;
}

FloatRect Player::getLeft()
{
	return p_left;
}

Sprite Player::getSprite()
{
	return p_sprite;
}

void Player::stopRight(float position)
{
	p_position.x = position - p_sprite.getGlobalBounds().width;
	p_sprite.setPosition(p_position);
}

void Player::stopLeft(float position)
{
	p_position.x = position + p_sprite.getGlobalBounds().width;
	p_sprite.setPosition(p_position);
}

void Player::stopFalling(float position)
{
	p_position.y = position - getPosition().height;
	p_sprite.setPosition(p_position);
	p_isFalling = false;
}

void Player::stopJump()
{
	p_isJumping = false;
	p_isFalling = true;
}

Vector2f Player::getCenter()
{
	return Vector2f(p_position.x + p_sprite.getGlobalBounds().width / 2, p_position.y + p_sprite.getGlobalBounds().height / 2);
}

void Player::update(float elapsedTime)
{
	if (p_rightPressed)
	{
		p_position.x += p_speed * elapsedTime;
	}

	if (p_leftPressed)
	{
		p_position.x -= p_speed * elapsedTime;
	}

	// Handle Jumping
	if (p_isJumping)
	{
		// Update how long the jump has been going
		p_timeThisJump += elapsedTime;

		// Is the jump going upwards
		if (p_timeThisJump < p_jumpDuration)
		{
			// Move up at twice gravity
			p_position.y -= p_gravity * 2 * elapsedTime;
		}
		else
		{
			p_isJumping = false;
			p_isFalling = true;
		}

	}

	// Apply gravity
	if (p_isFalling)
	{
		p_position.y += p_gravity * elapsedTime;
	}

	FloatRect r = getPosition();

	p_head.left = r.left;
	p_head.top = r.top + (r.height * .3);
	p_head.width = r.width;
	p_head.height = 1;

	p_feet.left = r.left + 3;
	p_feet.top = r.top + r.height - 1;
	p_feet.width = r.width - 6;
	p_feet.height = 1;

	p_right.left = r.left + r.width - 2;
	p_right.top = r.top + r.height * .35;
	p_right.width = 1;
	p_right.height = r.height * .3;

	p_left.left = r.left;
	p_left.top = r.top + r.height * .5;
	p_left.width = 1;
	p_left.height = r.height * .3;

	p_sprite.setPosition(p_position);
}
