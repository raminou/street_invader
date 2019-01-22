#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <tuple>
#include "game.hh"

typedef enum t_state {SMenu, SGame} State;

class Window
{
	private:
		sf::RenderWindow m_window;
		State m_state;
        Player m_player;
        Game* m_game;
        sf::RectangleShape m_rect_player;
        std::list<sf::RectangleShape*> m_list_rect_shots;
        std::list<sf::RectangleShape*> m_list_rect_enemies;
		int m_banner_position;
		sf::Texture m_window_texture_logo; 	
        sf::Sprite m_window_sprite_logo;    
        sf::Texture m_window_texture_banner; 	
        sf::Sprite m_window_sprite_banner;  
		
		// Font
		std::tuple<bool, sf::Font> m_font_score;
		std::tuple<bool, sf::Font> m_font_banner;
	
	public:
		static constexpr std::size_t banner_velocity = 1;
	
		Window(int size_window_x, int size_window_y);
        void main_loop();
        void refresh_screen();
		void display_info();
};
