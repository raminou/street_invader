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
		sf::Texture m_window_texture_logo;
        sf::Sprite m_window_sprite_logo;
        sf::Texture m_window_texture_banner;
        sf::Sprite m_window_sprite_banner;
        sf::Texture m_window_texture_background;
        sf::Sprite m_window_sprite_background;
		
		// Buttons
		std::map<std::string, Button> m_buttons;
		Button m_button_start;
		Button m_button_quit;
		
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
