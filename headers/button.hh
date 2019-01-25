#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>

/*
 * Class Button
 * Class to manage the display of buttons and to check a position of a click
 */
class Button
{
	private:
		int m_x;					// Position in x
		int m_y;					// Position in y
		std::size_t m_size_x;		// Size X
		std::size_t m_size_y;		// Size Y
		sf::Text m_text;			// Text to display
	
	public:
		// Constructors and Destructor
		Button() {}		// For the map
		Button(int x, int y, std::size_t size_x, std::size_t size_y, sf::Text t);
	
		// Getters
		sf::Text& get_text();
		
		// To check if the pos_x, pos_y match with the button position
		bool got_clicked(int pos_x, int pos_y) const;
		
		// Draw the button in the window
		void draw(sf::RenderWindow& win);
};