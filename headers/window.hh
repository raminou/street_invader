#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <tuple>
#include <map>
#include "game.hh"
#include "button.hh"

typedef enum t_state {SMenu, SGame, SEndGame} State;

class Window
{
	private:
		sf::RenderWindow m_window;
		State m_state;
        Player m_player;
        Game* m_game;
        sf::RectangleShape m_rect_player;
		int m_banner_position;

		//Graphic material
		sf::Texture m_window_texture_logo;
        sf::Sprite m_window_sprite_logo;
        sf::Texture m_window_texture_banner;
        sf::Sprite m_window_sprite_banner;
        sf::Texture m_window_texture_background_game;
        sf::Sprite m_window_sprite_background_game;
        sf::Texture m_window_texture_background_menu;
        sf::Sprite m_window_sprite_background_menu;
        sf::Texture m_window_texture_background_lose;
        sf::Sprite m_window_sprite_background_lose;
        sf::Texture m_window_texture_background_win;
        sf::Sprite m_window_sprite_background_win;
		
		// Buttons
		std::map<std::string, Button> m_buttons_menu;
		std::map<std::string, Button> m_buttons_endgame;
		
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
