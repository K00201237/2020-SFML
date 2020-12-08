#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
protected:
	Sprite p_sprite;

	bool p_leftPressed;
	bool p_rightPressed;

private:

	float p_speed = 400;

	Vector2f p_position;

	FloatRect p_feet;
	FloatRect p_head;
	FloatRect p_right;
	FloatRect p_left;

	Texture p_texture;

public:

	void spawn(Vector2f startPosition, float gravity);
	bool virtual handleInput() = 0;

	FloatRect getPosition();

	FloatRect getHead();
	FloatRect getFeet();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	void stopRight(float position);
	void stopLeft(float position);


	Vector2f getCenter();

	void update(float elapsedTime);



};