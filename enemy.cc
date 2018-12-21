#include "enemy.hh"

Enemy::Enemy(int x, int y, int hp): Character(x, y, Enemy::size, hp)
{
}

void Enemy::move(){}

Shot* Enemy::shoot(){
	return nullptr;
}
