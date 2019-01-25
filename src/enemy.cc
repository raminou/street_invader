#include "enemy.hh"

Enemy::Enemy(int x, int y, int size, int hp): Character(x, y, size, hp)
{
	if (!m_texture.loadFromFile("resources/texture/gilet_jaune.png")) {
    	std::cout << "Error loading gilet_jaune.png" << std::endl;
    }
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(x, y);
    m_sprite.setScale(0.15f, 0.15f);
}

Enemy::~Enemy(){}

void Enemy::move(Direction_t direction, int min_x, int max_x) {
	switch(direction) {
		case UP:
			m_y -= m_enemy_velocity;
			break;
		case DOWN:
			m_y += m_enemy_velocity;
			break;
		case LEFT:
			if(m_x > min_x)
				m_x -= m_enemy_velocity;
			break;
		case RIGHT:
			if(m_x < max_x)
				m_x += m_enemy_velocity;
			break;
		default:
			return;
	}
}

Shot* Enemy::shoot() const{
	return new Shot(m_x + m_size/2, m_y + m_size/2, (Enemy*)this, DOWN);
}

void Enemy::reduce_hp() {
    if(this->m_hp >= 0)
        this->m_hp--;
}

std::ostream& operator<<(std::ostream& os, const Enemy& en) {
	os << "Enemy<" << en.get_x() << "," << en.get_y() << ">;" << std::endl;
	return os;
}