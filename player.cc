#include "player.hh"

Player::Player(int x, int y, int hp, std::string name) : Character(x, y, Player::m_player_size, hp), m_name(name) {}

Player::~Player() {}

void Player::move()
{}

Shot* Player::shoot()
{
	return nullptr;
}
