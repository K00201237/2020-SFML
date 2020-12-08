#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	// Of course we will need a sprite
	Sprite m_Sprite;


	// Which directions is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;



	// Private variables and functions come next
private:

	// How fast is the character
	float m_Speed = 400;

	// Where is the player
	Vector2f m_Position;

	// Where are the characters various body parts?
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	// And a texture
	Texture m_Texture;

	// All our public functions will come next
public:

	void spawn(Vector2f startPosition, float gravity);

	// This is a pure virtual function
	bool virtual handleInput() = 0;
	// This class is now abstract and cannot be instanciated

	// Where is the player
	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// Make the character stand firm
	void stopRight(float position);
	void stopLeft(float position);


	// Where is the center of the character
	Vector2f getCenter();

	// We will call this function once every frame
	void update(float elapsedTime);
};
