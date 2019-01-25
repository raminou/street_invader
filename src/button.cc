#include "button.hh"
#include <iostream>

Button::Button(int x, int y, std::size_t size_x, std::size_t size_y, sf::Text t): 
	m_x(x),
	m_y(y),
	m_size_x(size_x),
	m_size_y(size_y),
	m_text(t)
{
	m_text.setPosition(x + 5, y + 5);
}

// Getters
sf::Text& Button::get_text()
{
	return m_text;
}

bool Button::got_clicked(int pos_x, int pos_y) const {
	return (m_x <= pos_x && pos_x <= (int)(m_x + m_size_x)) && (m_y <= pos_y && pos_y <= (int)(m_y + m_size_y));
}

void Button::draw(sf::RenderWindow& win) {
	win.draw(m_text);
}