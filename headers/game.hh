#pragma once

#include <list>

#include "player.hh"
#include "shot.hh"
#include "enemy.hh"

typedef enum GState {Unfinished, PlayerWon, EnemiesWon} GameState;

class Game
{
	private:
		int m_size_window_x;
		int m_size_window_y;
		int m_delay;
		Player* m_player;
		std::list<Shot*> m_list_shot;
		std::list<Enemy*> m_list_enemy;
		GameState m_game_state;
		unsigned int m_nb_shot;
		unsigned int m_nb_hit;
		unsigned int m_nb_enemies_begin;
	
	public:
		static constexpr std::size_t delay_down = 50;
		static int left_right;
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
        
		void player_move(Direction_t dir);
		void player_shot();
		void progress();
		void progress_shot();
		void generate();
};
