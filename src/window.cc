#include "window.hh"

Window::Window(int size_window_x, int size_window_y):
    m_window(sf::VideoMode(size_window_x, size_window_y), "TEST"),
	m_state(SGame),
    m_player(0, 0, 0, "toto"),
    m_game(nullptr),
    m_rect_player(sf::Vector2f(Player::m_player_size, Player::m_player_size)),
	m_banner_position(size_window_x),
	m_font_score(std::make_tuple(false, sf::Font())),
	m_font_banner(std::make_tuple(false, sf::Font()))
{
	m_window.setFramerateLimit(60);
    m_game = new Game(size_window_x, size_window_y-100, &m_player);
    m_rect_player.setFillColor(sf::Color(255, 0, 0));
	
	// Load font if it is possible
	if(!std::get<1>(m_font_score).loadFromFile("resources/font/firstgradelili.ttf")) {
		std::cout << "Error loading firstgradelili font" << std::endl;
	}
	else
		std::get<0>(m_font_score) = true;
		
	// Load font if it is possible
	if(!std::get<1>(m_font_banner).loadFromFile("resources/font/univers-condensed-bold.ttf")) {
		std::cout << "Error loading kids_magazine font" << std::endl;
	}
	else
		std::get<0>(m_font_banner) = true;

/*
	if (!m_player.get_texture().loadFromFile("resources/texture/macron.png")) {
    	std::cout << "Error loading macron.png" << std::endl;
    }
    m_player.get_texture().setSmooth(true);
    m_player.get_sprite().setTexture(m_player.get_texture());
    m_player.get_sprite().setPosition(m_player.get_x(), m_player.get_y());
    m_player.get_sprite().setScale(0.2f, 0.2f);
*/
	if (!m_window_texture_banner.loadFromFile("resources/texture/banner.png")) {
    	std::cout << "Error loading banner.png" << std::endl;
    }
    m_window_sprite_banner.setTexture(m_window_texture_banner);
    m_window_sprite_banner.setScale(0.5f, 0.25f);
    

    if (!m_window_texture_logo.loadFromFile("resources/texture/bfm.png")) {
    	std::cout << "Error loading bfm.png" << std::endl;
    }
    m_window_sprite_logo.setTexture(m_window_texture_logo);
    m_window_sprite_logo.setScale(0.2f, 0.2f);

}

void Window::refresh_screen()
{
	int i;
	sf::RectangleShape* rect_tmp = nullptr;
	sf::Sprite sprite;
	switch(m_state) {
		case SGame:

			//Banner
			sprite = m_window_sprite_banner;
    		m_window_sprite_banner.setPosition(0, m_game->get_size_y() + 50);
    		m_window.draw(m_window_sprite_banner);
    		
    		sprite = m_window_sprite_logo;
    		m_window_sprite_logo.setPosition(0, m_game->get_size_y() + 50);
    		m_window.draw(m_window_sprite_logo);
		
			// Player
			// std::cout << "pos x:" << m_player.get_x() << ", y:" << m_player.get_y() << std::endl;
			//m_rect_player.setPosition(m_player.get_x(), m_player.get_y());
			//m_window.draw(m_rect_player);
			std::cout << "x = " << m_player.get_x() << " y = " << m_player.get_y() << std::endl;
			sprite = m_player.get_sprite();
			sprite.setPosition(m_player.get_x(), m_player.get_y());
			m_window.draw(sprite);
			//std::cout << "bouge" << std::endl;

			// Enemies
			this->m_list_rect_enemies.clear();
			// std::cout << "size: " << m_game->get_enemies().size() << std::endl;
			i = 255;
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

			display_info();
			break;
		case SMenu:
			break;
	}
}

void Window::display_info()
{
	std::string msg = "SCORE: " + std::to_string(m_player.get_score());
	//std::cout << msg << std::endl;
	sf::Text text_score;
	
	if(std::get<0>(m_font_score))
		text_score.setFont(std::get<1>(m_font_score));
	
	text_score.setString(msg);
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::Blue);
	text_score.setPosition(10, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	// Banner
	msg = std::to_string(m_game->get_enemies().size() * 100) + " GILETS JAUNES ENCORE DANS LES RUES. EMMANUEL MACRON SUR LE TERRAIN POUR LES ARRETER.";
	sf::Text text_banner;
	if(std::get<0>(m_font_banner))
		text_banner.setFont(std::get<1>(m_font_banner));
	
	text_banner.setString(msg);
	text_banner.setCharacterSize(30);
	text_banner.setFillColor(sf::Color::White);
	text_banner.setPosition(m_banner_position, m_game->get_size_y() + 55);
	m_window.draw(text_banner);
	// sf::RectangleShape;
	
	m_banner_position -= Window::banner_velocity;
	if(m_banner_position + text_banner.getLocalBounds().width < 0)
		m_banner_position = m_game->get_size_x();
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