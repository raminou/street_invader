#pragma once

#include <SFML/Graphics.hpp>
#include "game.hh"

class Window
{
	private:
		sf::RenderWindow m_window;
		Game* m_game;
	
	public:
		Window(int size_window_x, int size_window_y);
};
