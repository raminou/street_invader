#pragma once

#include "character.hh"

class Enemy: public Character
{
	public:
		static constexpr std::size_t m_enemy_size = 25;			//Size
		static constexpr std::size_t m_enemy_velocity = 5;		//Velocity of a Shot object (value to modify)
		static constexpr std::size_t score_enemy = 100;


		Enemy(int x, int y, int hp);
		virtual ~Enemy();
        
        void reduce_hp();
		void move(Direction_t direction, int min_x, int max_x);
		Shot* shoot() const;
};
