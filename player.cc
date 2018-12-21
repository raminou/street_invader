#include "player.hh"

Player::Player(int x, int y, int hp, std::string name) : Character(x, y, Player::m_player_size, hp), m_name(name) {}

Player::~Player() {}

Shot* Player::shoot() const
{
	return nullptr;
}

void Player::move(Direction_t direction) {
	// switch(direction) {
		// case LEFT:
			// m_y -= m_shot_velocity;
		// case DOWN:
			// m_y += m_shot_velocity;
		// default:
			// return;
	// }
}
