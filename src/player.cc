#include "player.hh"

Player::Player(int x, int y, int size, int hp, std::string name):
	Character(x, y, size, hp),
	m_name(name),
	m_score(0)
{
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

std::ostream& operator<<(std::ostream& os, const Player& p) {
	os << "Player<" << p.get_x() << "," << p.get_y() << ">;" << std::endl;
	return os;
}

void Player::reset_score() {
	m_score = 0;
}

void Player::move(Direction_t direction, int min_x, int max_x) {
	switch(direction) {
		case LEFT:
			if(this->m_x > min_x)
				this->m_x -= m_player_velocity;
            break;
		case RIGHT:
			if(this->m_x < max_x)
				this->m_x += m_player_velocity;
            break;
		default:
			return;
	}
}

Shot* Player::shoot() const {
	return new Shot(m_x + m_size/2, m_y - m_size/2, (Player*)this, UP);
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