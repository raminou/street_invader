#include "player.hh"

Player::Player(int x, int y, int hp, string name) : Character(x, y, 5, hp), m_name(name) {}



Player::~Player() {}
