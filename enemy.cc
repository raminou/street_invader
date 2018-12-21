#include "enemy.hh"

Enemy::Enemy(int x, int y, int hp): Character(x, y, Enemy::size, hp)
{
}

Enemy::~Enemy(){}

void Enemy::move(Direction_t direction) {
	// this->m_x = 0;
}

Shot* Enemy::shoot() const{
	return nullptr;
}
