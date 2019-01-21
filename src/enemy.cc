#include "enemy.hh"

Enemy::Enemy(int x, int y, int hp): Character(x, y, Enemy::m_enemy_size, hp)
{
}

Enemy::~Enemy(){}

void Enemy::move(Direction_t direction) {
	switch(direction) {
		case UP:
			m_y -= m_enemy_velocity;
		case DOWN:
			m_y += m_enemy_velocity;
		case LEFT:
			m_x -= m_enemy_velocity;
		case RIGHT:
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