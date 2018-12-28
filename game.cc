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
Player* Game::get_player() const {
    return m_player;
}

std::list<Shot*> Game::get_shots() const {
    return m_list_shot;
}

std::list<Enemy*> Game::get_enemies() const {
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
    int distance_x = 25;
    int distance_y = 25;
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
            padding_y += distance_y + Enemy::m_enemy_size;
        }
    }
    
    // Setting the player in the middle of the screen
    m_player->change_position(m_size_window_x/2 - Player::m_player_size/2, m_size_window_y - 25);
}

void Game::progress_shot() {
    for(auto& ite : m_list_shot)
    {
        ite->move();
    }
    
    // for(Shot* ite : m_list_shot)
    for(auto ite = m_list_shot.begin(); ite != m_list_shot.end(); ite++)
    {
        Player* tmp_author = dynamic_cast<Player*>((*ite)->get_author());
        if(tmp_author != nullptr)
        {
            // If the author is a player, we are checking collision with enemies
            Enemy* enemy_hit = nullptr;
            for(const Enemy* ite_enemy : m_list_enemy)
            {
                if(ite_enemy->check_hit(*ite))
                {
                    enemy_hit = (Enemy*)ite_enemy;
                    break;
                }
            }
            
            // If an enemy has been hit
            if(enemy_hit != nullptr)
            {
                enemy_hit->reduce_hp();
                
                if(enemy_hit->get_hp() == 0)
                {
                    // m_list_shot.erase(ite);
                }
            }
        }
        else
        {
            // Else we are checking collision with the player
            if((*ite)->check_hit(m_player))
            {
                
            }
        }
    }
}