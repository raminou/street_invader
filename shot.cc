#include "shot.hh"


Shot::Shot(int x, int y, Character* author, Direction_t direction) : Entity(x, y, 5), m_author(author), m_direction(direction) {}



Shot::~Shot() {}



void Shot::move(Direction_t direction) {
	m_x += direction * m_shot_velocity;
	m_y += direction * m_shot_velocity;
}