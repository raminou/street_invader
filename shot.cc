#include "shot.hh"


Shot::Shot(int x, int y, const Character* author, Direction_t direction) : Entity(x, y, 5), m_author(author), m_direction(direction) {}

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

const Character* Shot::get_author() const {
    return m_author;
}