#pragma once

#include <list>
#include <ctime>

#include "player.hh"
#include "shot.hh"
#include "enemy.hh"

/*
 * Typedef to manage the state of the Game:
 *  - Unfinished: means that the game continue
 *  - PlayerWon: means that the player won
 *  - EnemiesWon: means that the enemies won
 */
typedef enum GState {Unfinished, PlayerWon, EnemiesWon} GameState;

/*
 * Class Window
 * Class to manage the game, the rules and the action of anyone
 */
class Game
{
	private:
		int m_size_window_x;				// Size of the game X
		int m_size_window_y;				// Size of the game Y
		int m_delay;						// Delay to wait until that the enemy will move
		Player* m_player;					// Player
		std::list<Shot*> m_list_shot;		// List of shots
		std::list<Enemy*> m_list_enemy;		// List of enemies
		GameState m_game_state;				// State of the game
	
		// Counters
		unsigned int m_nb_shot;				// Counter of shots
		unsigned int m_nb_hit;				// Counter of hits
		unsigned int m_nb_enemies_begin;	// Number of enemies at the beginning
	
		// Time
		std::time_t m_time_begin;			// Timestamp UNIX at the start
		std::time_t m_time_end;				// Timestamp UNIX at the end
	
	public:
		static constexpr std::size_t delay_down = 50;	// Delay to move enemies
		static int left_right;				// Move enemies
		
		// Constructor and Destructor
		Game(int size_window_x, int size_window_y, Player* p);
		~Game();

		// Getters
		Player* get_player() const;
		std::list<Shot*> get_shots() const;
		std::list<Enemy*> get_enemies() const;
		int get_size_x() const;
		int get_size_y() const;
		GameState get_game_state() const;
		unsigned int get_nb_shot() const;
		unsigned int get_nb_hit() const;
		unsigned int get_nb_enemies_begin() const;
		std::time_t get_time() const;
        
		// Actions
		// The player move
		void player_move(Direction_t dir);
	
		// The player shoot
		void player_shot();
	
		// We make progress enemies and shots
		void progress();
	
		// We make progress shots
		void progress_shot();
	
		// We generate the list of the enemies
		void generate();
};
