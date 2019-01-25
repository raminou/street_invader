#pragma once
#include "character.hh"
#include <string>

/*
 * Class Player
 * Class managing the action of the player
 */
class Player : public Character {
	private:
		std::string m_name;				// Name of the player
		unsigned int m_score;			// Score of the player
	
	public:
		static constexpr std::size_t m_player_size = 40;		// Size of a Player object
		static constexpr std::size_t m_player_velocity = 5;		// Velocity of a Player object

		// Constructor and destructor
		Player(int x, int y, int size, int hp, std::string name);
		virtual ~Player();
	
		// Getters
		unsigned int get_score() const;
		std::string get_name() const;
	
		// Debug method
		friend std::ostream& operator<<(std::ostream& , const Character&);

		// Reset score at the beginning of a new game
		void reset_score();
	
		// Movement
		void move(Direction_t direction, int min_x, int max_x);
	
		// Change the position to reset position at the beginning of a new game
		void change_position(int x, int y);
	
		// Shoot
		Shot* shoot() const;
	
		// Add score
		void add_score(int s);
	
		// Sub score
		void sub_score(int s);
};
