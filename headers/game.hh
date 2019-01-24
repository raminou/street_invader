#pragma once

#include <list>

#include "player.hh"
#include "shot.hh"
#include "enemy.hh"

class Game
{
	private:
		int m_size_window_x;
		int m_size_window_y;
		int m_delay;
		Player* m_player;
		std::list<Shot*> m_list_shot;
		std::list<Enemy*> m_list_enemy;
	
	public:
		static constexpr std::size_t delay_down = 100;
        // Constructor and Destructor
		Game(int size_window_x, int size_window_y, Player* p);
        ~Game();
        
        // Getters
        Player* get_player() const;
        std::list<Shot*> get_shots() const;
        std::list<Enemy*> get_enemies() const;
		int get_size_x() const;
		int get_size_y() const;
        
		void player_move(Direction_t dir);
		void player_shot();
		void progress();
		void progress_shot();
		void generate();
};
