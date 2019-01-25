#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <tuple>
#include <map>
#include "game.hh"
#include "button.hh"

/*
 * Typedef to manage the state of the Window:
 *  - SMenu: means we are in the menu
 *  - SGame: means we are in the game
 *  - SEndGame: means we just finished the game
 */
typedef enum t_state {SMenu, SGame, SEndGame} State;

/*
 * Class Window
 * Class to manage the window, the display of the game and the informations about it
 */
class Window
{
	private:
		sf::RenderWindow m_window;			// Window Object of SFML
		State m_state;						// State of the window
		Player m_player;					// Player
		Game* m_game;						// Game* (nullptr) if the game does not begin

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
		
		// Fonts
		sf::Font m_font_score;
		sf::Font m_font_banner;
	
	public:	
		// Constructor
		Window(int size_window_x, int size_window_y);
		
		// Main Loop
		void main_loop();
		
		// Refresh the screen
		void refresh_screen();
	
		// Display the info of the game
		void display_info();
};
