#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "game.hh"

class Window
{
	private:
		sf::RenderWindow m_window;
        Player m_player;
        Game* m_game;
        sf::RectangleShape m_rect_player;
        std::list<sf::RectangleShape*> m_list_rect_shots;
        std::list<sf::RectangleShape*> m_list_rect_enemies;
	
	public:
		Window(int size_window_x, int size_window_y);
        void main_loop();
        void refresh_screen();
};
