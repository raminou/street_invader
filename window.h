#pragma once

#include <SFML/Graphics.hpp>
#include "game.h"

class Window
{
	private:
		sf::RenderWindow m_window;
		Game* m_game;
	
	public:
		Window();
};
