#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// These calls to spawn will be moved to a new
		// LoadLevel function soon
		// Spawn Thomas and Bob
		p_playerChar.spawn(Vector2f(0, 0), GRAVITY);


		// Make sure spawn is called only once
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}

	if (m_Playing)
	{
		m_MainView.setCenter(p_playerChar.getCenter());
		// Update player
		p_playerChar.update(dtAsSeconds);


		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}// End if playing

	
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(p_playerChar.getCenter());
	}
	else
	{
		// Centre full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(p_playerChar.getCenter());
		}
		else
		{

		}
	}
	
}