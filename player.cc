#include "player.hh"

Player::Player(int x, int y, int hp, std::string name) : Character(x, y, Player::m_player_size, hp), m_name(name) {}



Player::~Player() {}



void Player::move(Direction_t direction) {
	switch(direction) {
		case LEFT:
			m_y -= m_player_velocity;
		case DOWN:
			m_y += m_player_velocity;
		default:
			return;
	}
}



Shot* Player::shoot() const {
	return nullptr;
}