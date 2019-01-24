#include "enemy.hh"

Enemy::Enemy(int x, int y, int size, int hp): Character(x, y, size, hp)
{
	if (!m_texture.loadFromFile("resources/texture/gilet_jaune.png")) {
    	std::cout << "Error loading macron.png" << std::endl;
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
		case DOWN:
			m_y += m_enemy_velocity;
		case LEFT:
			if(m_x > min_x) 
				m_x -= m_enemy_velocity;
		case RIGHT:
			if(m_x < max_x)
				m_x += m_enemy_velocity;
		default:
			return;
	}
}

Shot* Enemy::shoot() const{
	return new Shot(m_x + m_size/2, m_y + 1, (Enemy*)this, DOWN);
}

void Enemy::reduce_hp() {
	std::cout << "reducehp: " << m_hp << std::endl;
    if(this->m_hp >= 0)
        this->m_hp--;
}