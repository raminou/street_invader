#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>

class Button
{
	private:
		int m_x;
		int m_y;
		std::size_t m_size_x;
		std::size_t m_size_y;
		sf::Text m_text;
		sf::RectangleShape m_rect;
	
	public:
		Button(int x, int y, std::size_t size_x, std::size_t size_y, sf::Text t);
		Button() {}
	
		// Getters
		sf::Text& get_text();
	
		bool got_clicked(int pos_x, int pos_y) const;
		void draw(sf::RenderWindow& win);
};