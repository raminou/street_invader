#pragma once
#include "character.hh"
#include <string>


class Player : public Character {

	private:
		std::string m_name;								//Name of the player
		unsigned int m_score;						//Score of the player


	public:
		static constexpr std::size_t m_player_size = 20;		//Size of a Player object (value to modify)

		Player(int x, int y, std::size_t size, int hp, std::string name);
		virtual ~Player();
		virtual void move();  
		virtual Shot* shoot();	
};
