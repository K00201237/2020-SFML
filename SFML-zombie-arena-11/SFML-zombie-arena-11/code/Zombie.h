#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	// How fast is each zombie type?
	const float BLOATER_SPEED = 90;
	const float CHASER_SPEED = 120;
	const float CRAWLER_SPEED = 30;
	//const float EXPLODER_SPEED = 150;

	// How tough is each zombie type
	const float BLOATER_HEALTH = 10;
	const float CHASER_HEALTH = 2;
	const float CRAWLER_HEALTH = 6;
	//const float EXPLODER_HEALTH = 1;

	// Make each zombie vary its speed slightly
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	// Where is this zombie?
	Vector2f m_Position;

	// A sprite for the zombie
	Sprite m_Sprite;

	// How fast can this one run/crawl?
	float m_Speed;

	// How much health has it got?
	float m_Health;

	// Is it still alive?
	bool m_Alive;

	// Public prototypes go here	
public:

	// Handle when a bullet hits a zombie
	bool hit();

	// Find out if the zombie is alive
	bool isAlive();

	// Spawn a new zombie
	void spawn(float startX, float startY, int type, int seed);

	// Return a rectangle that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update the zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);

	int Zexploder;
};


