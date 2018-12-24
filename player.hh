#pragma once
#include "character.hh"
#include <string>


class Player : public Character {

	private:
		std::string m_name;				//Name of the player
		unsigned int m_score;			//Score of the player

	public:
		static constexpr std::size_t m_player_size = 20;		//Size of a Player object (value to modify)
		static constexpr std::size_t m_player_velocity = 5;		//Velocity of a Shot object (value to modify)

        // Constructor and destructor
		Player(int x, int y, int hp, std::string name);
		virtual ~Player();

		void move(Direction_t direction);
        void change_position(int x, int y);
		Shot* shoot() const;
};
