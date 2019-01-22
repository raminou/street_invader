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
	
		// Getters
		unsigned int get_score() const;
		std::string get_name() const;

		void move(Direction_t direction, int min_x, int max_x);
        void change_position(int x, int y);
		Shot* shoot() const;
		void add_score(int s);
		void sub_score(int s);
};
