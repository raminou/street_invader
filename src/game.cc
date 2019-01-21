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
        m_list_enemy.push_back(new Enemy(padding_x, padding_y, 0));
        padding_x += Enemy::m_enemy_size + distance_x;
        if((i+1) % 5 == 0)
        {
            padding_x = init_padding_x;
            padding_y += distance_y + Enemy::m_enemy_size;
        }
    }
    
    // m_list_enemy.push_back(new Enemy(400, 50, 0));
    
    // Setting the player in the middle of the screen
    m_player->change_position(m_size_window_x/2 - Player::m_player_size/2, m_size_window_y - 25);
}

void Game::progress_shot() {
    // std::cout << "sizel: " << m_list_shot.size() << std::endl;
    // Move shots and erase if they are out of the window
    std::list<Shot*>::iterator ite = m_list_shot.begin();
    while(ite != m_list_shot.end())
    {
        (*ite)->move();
        if((*ite)->get_y() < 0 || (*ite)->get_y() >= m_size_window_y || (*ite)->get_x() < 0 || (*ite)->get_x() >= m_size_window_x)
            ite = m_list_shot.erase(ite);
        else
            ite++;
    }
    
    ite = m_list_shot.begin();
    while(ite != m_list_shot.end())
    {
        // std::cout << "ite x: " << (*ite)->get_x() << ", y: " << (*ite)->get_y() << std::endl;

        bool hit = false;
        Player* tmp_author = dynamic_cast<Player*>((*ite)->get_author());
        if(tmp_author != nullptr)
        {
            // If the author is a player, we are checking collision with enemies
            std::list<Enemy*>::iterator ite_enemy;
            for(ite_enemy = m_list_enemy.begin(); ite_enemy != m_list_enemy.end(); ite_enemy++)
            {
                // If an enemy has been hit
                if((*ite_enemy)->check_hit((Entity&)(**ite)))
                {
                    hit = false;
                    std::cout << "enemy hit" << std::endl;
                    (*ite_enemy)->reduce_hp();

                    // Clear shot
                    ite = m_list_shot.erase(ite);

                    if((*ite_enemy)->get_hp() < 0)
                        m_list_enemy.erase(ite_enemy);
                    break;
                }
            }
            
            if(!hit)
                ite++;
        }
        else
        {
            // Else we are checking collision with the player
            if((*ite)->check_hit(*m_player))
            {
                ;
            }
        }
    }
    // std::cout << "endprogressshot" << std::endl;
}