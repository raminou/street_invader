#include "game.h"

Game::Game(int size_x, int size_y, const Player& p): m_size_window_x(size_x), m_size_window_y(size_y), m_player(p) {}

void Game::player_shot()
{
	m_list_shot.push_back(Shot(m_player.getX(), m_player.getY(), m_player));
}
