#include "player.hh"

Player::Player(int x, int y, int hp, std::string name) : Character(x, y, Player::m_player_size, hp), m_name(name) {}

Player::~Player() {}

void Player::move(Direction_t direction) {
	switch(direction) {
		case LEFT:
            std::cout << "MOVE LEFT: " << this->m_x << std::endl;
			this->m_x -= m_player_velocity;
            break;
		case RIGHT:
            std::cout << "MOVE RIGHT" << std::endl;
			this->m_x += m_player_velocity;
            break;
		default:
			return;
	}
}

Shot* Player::shoot() const {
	return new Shot(m_x + m_size/2, m_y - 1, this, UP);
}

void Player::change_position(int x, int y) {
    this->m_x = x;
    this->m_y = y;
}