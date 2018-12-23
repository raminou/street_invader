#include "game.hh"

// Constructor and Destructor
Game::Game(int size_x, int size_y, Player* p):
    m_size_window_x(size_x),
    m_size_window_y(size_y),
    m_player(p)
{
    generate();
}

Game::~Game()
{
    m_list_shot.clear();
    m_list_enemy.clear();
}

// Getters
Player* Game::get_player() {
    return m_player;
}

std::list<Shot*> Game::get_shots() {
    return m_list_shot;
}

std::list<Enemy*> Game::get_enemies() {
    return m_list_enemy;
}

void Game::player_shot()
{
	m_list_shot.push_back(m_player->shoot());
}

void Game::player_move(Direction_t dir)
{
    m_player->move(dir);
}

void Game::generate()
{
    // Creating enemies
    int distance_x = 5;
    int distance_y = 5;
    int init_padding_x = 10;
    int padding_x = init_padding_x;
    int padding_y = 10;
    
    for(int i = 0; i < 15; i++)
    {
        m_list_enemy.push_back(new Enemy(padding_x, padding_y, 1));
        padding_x += Enemy::m_enemy_size + distance_x;
        if((i+1) % 5 == 0)
        {
            padding_x = init_padding_x;
            padding_y = distance_y + Enemy::m_enemy_size;
        }
    }
}