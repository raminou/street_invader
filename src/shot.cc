#include "shot.hh"


Shot::Shot(int x, int y, Character* author, Direction_t direction):
	Entity(x, y, Shot::m_shot_size),
	m_author(author),
	m_direction(direction)
{}

Shot::~Shot() {}

void Shot::move() {
	switch(m_direction) {
		case UP:
			m_y -= m_shot_velocity;
            break;
		case DOWN:
			m_y += m_shot_velocity;
            break;
		default:
			return;
	}
}

Character* Shot::get_author() const {
    return m_author;
}