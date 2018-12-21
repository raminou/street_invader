#include "shot.hh"


Shot::Shot(int x, int y, Character* author, char direction) : Entity(x, y, 5), m_author(author), m_direction(direction) {}



Shot::~Shot() {}



void Shot::move(char direction) {
	m_x += direction * 5;
	m_y += direction * 5;
}