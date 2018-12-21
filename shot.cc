#include "shot.hh"


Shot::Shot(int x, int y, Character* author, Direction_t direction) : Entity(x, y, 5), m_author(author), m_direction(direction) {}

Shot::~Shot() {}

void Shot::move() {
	switch(m_direction) {
		case UP:
			m_y += m_shot_velocity;
		case DOWN:
			m_y -= m_shot_velocity;
		default:
			return;
	}
}