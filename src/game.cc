#include "game.hh"

// Constructor and Destructor
Game::Game(int size_x, int size_y, Player* p):
    m_size_window_x(size_x),
    m_size_window_y(size_y),
    m_delay(Game::delay_down),
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

int Game::get_size_x() const {
    return m_size_window_x;
}

int Game::get_size_y() const {
    return m_size_window_y;
}

// Actions
void Game::player_shot()
{
	m_list_shot.push_back(m_player->shoot());
}

void Game::player_move(Direction_t dir)
{
    m_player->move(dir, 0, m_size_window_x - Player::m_player_size);
}

void Game::generate()
{
    // Creating enemies
    int distance_x = 40;
    int distance_y = 40;
    int init_padding_x = 20;
    int padding_x = init_padding_x;
    int padding_y = 10;
    
    for(int i = 0; i < 45; i++)
    {
        m_list_enemy.push_back(new Enemy(padding_x, padding_y, 0));
        padding_x += Enemy::m_enemy_size + distance_x;
        if((i+1) % 15 == 0)
        {
            padding_x = init_padding_x;
            padding_y += distance_y + Enemy::m_enemy_size;
        }
    }
    
    // m_list_enemy.push_back(new Enemy(400, 50, 0));
    
    // Setting the player in the middle of the screen
    m_player->change_position(m_size_window_x/2 - Player::m_player_size/2, m_size_window_y - 25);
}

void Game::progress()
{
    m_delay--;
    if(m_delay == 0)
    {
        std::cout << "down" << std::endl;
        for(auto& ite: m_list_enemy)
        {
            ite->move(DOWN, 0, m_size_window_x);
            if((int) (ite->get_y() + ite->get_size()) > m_size_window_y)
            {
                // GJ ont gagné
            }
        }
        m_delay = Game::delay_down;
    }
    
    progress_shot();
}

void Game::progress_shot() {
    // std::cout << "sizel: " << m_list_shot.size() << std::endl;
    // Move shots and erase if they are out of the window
    std::list<Shot*>::iterator ite_shot = m_list_shot.begin();
    while(ite_shot != m_list_shot.end())
    {
        (*ite_shot)->move();
        if((*ite_shot)->get_y() < 0 || (*ite_shot)->get_y() >= m_size_window_y || (*ite_shot)->get_x() < 0 || (*ite_shot)->get_x() >= m_size_window_x)
            ite_shot = m_list_shot.erase(ite_shot);
        else
            ite_shot++;
    }
    
    ite_shot = m_list_shot.begin();
    while(ite_shot != m_list_shot.end())
    {
        // std::cout << "ite x: " << (*ite)->get_x() << ", y: " << (*ite)->get_y() << std::endl;

        bool hit = false;
        Player* tmp_author = dynamic_cast<Player*>((*ite_shot)->get_author());
        if(tmp_author != nullptr)
        {
            // If the author is a player, we are checking collision with enemies
            std::list<Enemy*>::iterator ite_enemy;
            for(ite_enemy = m_list_enemy.begin(); ite_enemy != m_list_enemy.end(); ite_enemy++)
            {
                // If an enemy has been hit
                if((*ite_enemy)->check_hit((Entity&)(**ite_shot)))
                {
                    hit = false;
                    std::cout << "enemy hit" << std::endl;
                    (*ite_enemy)->reduce_hp();
                    
                    tmp_author->add_score(Enemy::score_enemy);

                    // Clear shot
                    ite_shot = m_list_shot.erase(ite_shot);

                    if((*ite_enemy)->get_hp() < 0)
                        m_list_enemy.erase(ite_enemy);
                    break;
                }
            }
            
            if(!hit)
                ite_shot++;
        }
        else
        {
            // Else we are checking collision with the player
            if((*ite_shot)->check_hit(*m_player))
            {
                ;
            }
        }
    }
    // std::cout << "endprogressshot" << std::endl;
}