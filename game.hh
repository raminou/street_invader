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
		Player* m_player;
		std::list<Shot> m_list_shot;
		std::list<Enemy> m_list_enemy;
	
	public:
		Game(int size_window_x, int size_window_y, Player* p);
		void player_move();
		void player_shot();
		void progress_shot();
		void generate();
};
