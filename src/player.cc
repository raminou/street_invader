#include "player.hh"

Player::Player(int x, int y, int hp, std::string name) : Character(x, y, Player::m_player_size, hp), m_name(name), m_score(0) {

	if (!m_texture.loadFromFile("resources/texture/macron.png")) {
    	std::cout << "Error loading macron.png" << std::endl;
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);
    m_sprite.setScale(0.2f, 0.2f);
}

Player::~Player() {}

// Getters
unsigned int Player::get_score() const {
	return m_score;
}

std::string Player::get_name() const {
	return m_name;
}
/*
sf::Sprite Player::get_sprite() const
{
    return m_player_sprite;
}
*/
void Player::move(Direction_t direction, int min_x, int max_x) {
	switch(direction) {
		case LEFT:
            std::cout << "MOVE LEFT: " << this->m_x << std::endl;
			if(this->m_x > min_x)
				this->m_x -= m_player_velocity;
            break;
		case RIGHT:
            std::cout << "MOVE RIGHT" << std::endl;
			if(this->m_x < max_x)
				this->m_x += m_player_velocity;
            break;
		default:
			return;
	}
}

Shot* Player::shoot() const {
	return new Shot(m_x + m_size/2, m_y - 1, (Player*)this, UP);
}

void Player::change_position(int x, int y) {
    this->m_x = x;
    this->m_y = y;
}

void Player::add_score(int s) {
	m_score += s;
}

void Player::sub_score(int s) {
	m_score -= s;
}