#pragma once

#include "character.hh"

class Enemy: public Character
{
	public:
		static constexpr std::size_t m_enemy_size = 35;			//Size
		static constexpr std::size_t m_enemy_velocity = 15;		//Velocity of an Enemy object
		static constexpr std::size_t score_enemy = 100;			//Score earned when you kill an enemy

		// Constructor & Destructor
		Enemy(int x, int y, int size, int hp);
		virtual ~Enemy();
		
		friend std::ostream& operator<<(std::ostream& , const Enemy&);
		
		void reduce_hp();
		void move(Direction_t direction, int min_x, int max_x);
		Shot* shoot() const;
};
