#pragma once

#include "character.hh"

class Enemy: public Character
{
	public:
		static constexpr int size = 20;
		Enemy(int x, int y, int hp);
		void move();
		Shot* shoot();
};

