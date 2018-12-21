#pragma once

#include "character.hh"

class Enemy: public Character
{
	public:
		static constexpr std::size_t m_enemy_size = 20;			//Size
		static constexpr std::size_t m_enemy_velocity = 5;		//Velocity of a Shot object (value to modify)


		Enemy(int x, int y, int hp);
		virtual ~Enemy();
		void move(Direction_t direction);
		Shot* shoot() const;
};
