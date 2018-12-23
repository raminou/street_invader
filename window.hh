#pragma once

#include <SFML/Graphics.hpp>
#include "game.hh"

class Window
{
	private:
		sf::RenderWindow m_window;
        Player m_player;
        Game* m_game;
	
	public:
		Window(int size_window_x, int size_window_y);
        void main_loop();
        void refresh_screen();
};
