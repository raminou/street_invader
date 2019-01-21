#include "window.hh"

Window::Window(int size_window_x, int size_window_y):
    m_window(sf::VideoMode(size_window_x, size_window_y), "TEST"),
    m_player(0, 0, 0, "toto"),
    m_game(nullptr),
    m_rect_player(sf::Vector2f(Player::m_player_size, Player::m_player_size))
{
    m_game = new Game(size_window_x, size_window_y, &m_player);
    m_rect_player.setFillColor(sf::Color(255, 0, 0));
}

void Window::refresh_screen()
{
    sf::RectangleShape* rect_tmp = nullptr;
    
    // Player
    // std::cout << "pos x:" << m_player.get_x() << ", y:" << m_player.get_y() << std::endl;
    m_rect_player.setPosition(m_player.get_x(), m_player.get_y());
    m_window.draw(m_rect_player);
    
    // Enemies
    this->m_list_rect_enemies.clear();
    // std::cout << "size: " << m_game->get_enemies().size() << std::endl;
    int i = 255;
    for(auto& ite : m_game->get_enemies())
    {
        rect_tmp = new sf::RectangleShape(sf::Vector2f(Enemy::m_enemy_size, Enemy::m_enemy_size));
        rect_tmp->setPosition(ite->get_x(), ite->get_y());
        rect_tmp->setFillColor(sf::Color(0, i, 255));
        m_window.draw(*rect_tmp);
        m_list_rect_enemies.push_back(rect_tmp);
        i -= 10;
    }
    
    // Shots
    this->m_list_rect_shots.clear();
    for(auto& ite : m_game->get_shots())
    {
        rect_tmp = new sf::RectangleShape(sf::Vector2f(Shot::m_shot_size, Shot::m_shot_size));
        rect_tmp->setPosition(ite->get_x(), ite->get_y());
        rect_tmp->setFillColor(sf::Color(0, 255, 0));
        m_window.draw(*rect_tmp);
        m_list_rect_shots.push_back(rect_tmp);
    }
}

void Window::main_loop()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Left:
                            m_game->player_move(LEFT);
                            std::cout << "LEFT" << std::endl;
                            break;
                        case sf::Keyboard::Right:
                            m_game->player_move(RIGHT);
                            std::cout << "Right" << std::endl;
                            break;
                        case sf::Keyboard::Space:
                            m_game->player_shot();
                            std::cout << "space" << std::endl;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        m_window.clear();
        m_game->progress_shot();

        // Draw
        refresh_screen();
        
        m_window.display();
    }
}