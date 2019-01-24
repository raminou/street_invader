#include "window.hh"

Window::Window(int size_window_x, int size_window_y):

    m_window(sf::VideoMode(size_window_x, size_window_y), "Street Invaders"),
	m_state(SGame),
    m_player(0, 0, Player::m_player_size, 0, "E.Macron"),
    m_game(nullptr),
    m_rect_player(sf::Vector2f(Player::m_player_size, Player::m_player_size)),
	m_banner_position(size_window_x),
	m_buttons(std::map<std::string, Button>()),
	m_font_score(std::make_tuple(false, sf::Font())),
	m_font_banner(std::make_tuple(false, sf::Font()))
{
	m_window.setFramerateLimit(60);
    m_rect_player.setFillColor(sf::Color(255, 0, 0));
	
	// Load font if it is possible
	if(!std::get<1>(m_font_score).loadFromFile("resources/font/univers-condensed-bold.ttf")) {
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

	if (!m_window_texture_banner.loadFromFile("resources/texture/banner.png")) {
    	std::cout << "Error loading banner.png" << std::endl;
    }
    else {
    	m_window_sprite_banner.setTexture(m_window_texture_banner);
    	m_window_sprite_banner.setScale(0.5f, 0.25f);
    }
    

    if (!m_window_texture_background.loadFromFile("resources/texture/background.png")) {
    	std::cout << "Error loading background.jpg" << std::endl;
    }
    else {
	    m_window_sprite_background.setTexture(m_window_texture_background);
	    m_window_sprite_background.setScale(1.25f, 1.25f);
    }

	// Buttons
	m_buttons["start"] = Button(250, 150, 100, 50, sf::Text());
	m_buttons["quit"] = Button(250, 250, 100, 50, sf::Text());
	
	m_buttons["start"].get_text().setString("Start");
	m_buttons["start"].get_text().setFillColor(sf::Color::Red);
	if(std::get<0>(m_font_banner))
			m_buttons["start"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons["start"].get_text().setCharacterSize(50);
		
	m_buttons["quit"].get_text().setString("Quit");
	m_buttons["quit"].get_text().setFillColor(sf::Color::Red);
	if(std::get<0>(m_font_banner))
		m_buttons["quit"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons["quit"].get_text().setCharacterSize(50);
}

void Window::refresh_screen()
{
	sf::RectangleShape rect_tmp;
	sf::Sprite sprite;
	sf::Text title;
	sf::Text button_start;
	sf::Text button_quit;
	
	switch(m_state) {
		case SGame:

			//Background
			sprite = m_window_sprite_background;
    		m_window_sprite_background.setPosition(0, 0);
    		m_window.draw(m_window_sprite_background);

			//Banner
			sprite = m_window_sprite_banner;
    		m_window_sprite_banner.setPosition(0, m_game->get_size_y() + 50);
    		m_window.draw(m_window_sprite_banner);

			sprite = m_player.get_sprite();
			sprite.setPosition(m_player.get_x(), m_player.get_y());
			m_window.draw(sprite);
			

			// Enemies			
			for(auto& ite : m_game->get_enemies())
			{
				sprite = ite->get_sprite();
				sprite.setPosition(ite->get_x(), ite->get_y());
				m_window.draw(sprite);
			}

			// Shots
			for(auto& ite : m_game->get_shots())
			{
				rect_tmp = sf::RectangleShape(sf::Vector2f(Shot::m_shot_size, Shot::m_shot_size));
				rect_tmp.setPosition(ite->get_x(), ite->get_y());
				rect_tmp.setFillColor(sf::Color(0, 255, 0));
				m_window.draw(rect_tmp);
			}

			display_info();
			break;
		case SMenu:
			if(std::get<0>(m_font_banner))
				title.setFont(std::get<1>(m_font_banner));
			title.setString("Street Invaders");
			title.setFillColor(sf::Color::Yellow);
			title.setCharacterSize(50);
			title.setPosition(250, 50);
			m_window.draw(title);
			
			/*
			if(std::get<0>(m_font_banner))
				button_start.setFont(std::get<1>(m_font_banner));
			button_start.setString("Street invader");
			button_start.setFillColor(sf::Color::Yellow);
			button_start.setCharacterSize(30);
			button_start.setPosition(250, 150);
			m_window.draw(button_start);*/
			for(std::map<std::string, Button>::iterator ite = m_buttons.begin(); ite != m_buttons.end(); ite++)
				ite->second.draw(m_window);
			
			/*m_button_start.draw(m_window);
			m_button_quit.draw(m_window);*/
			
			break;
		case SEndGame:
			break;
	}
}

void Window::display_info()
{
	std::string msg = "SCORE : " + std::to_string(m_player.get_score());
	sf::Text text_score;
	
	if(std::get<0>(m_font_score))
		text_score.setFont(std::get<1>(m_font_score));
	
	text_score.setString(msg);
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(10, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	
	// Banner
	msg = std::to_string(m_game->get_enemies().size() * 100) + " GILETS JAUNES ENCORE DANS LES RUES.\nEMMANUEL MACRON SUR LE TERRAIN POUR LES ARRETER.";
	sf::Text text_banner;
	if(std::get<0>(m_font_banner))
		text_banner.setFont(std::get<1>(m_font_banner));
	
	text_banner.setString(msg);
	text_banner.setCharacterSize(20);
	text_banner.setFillColor(sf::Color::White);
	text_banner.setPosition(115, m_game->get_size_y() + 50);
	m_window.draw(text_banner);
}

void Window::main_loop()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
			if(m_state == SMenu && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(m_window);
				
				for(std::map<std::string, Button>::iterator ite = m_buttons.begin(); ite != m_buttons.end(); ite++)
				{
					if(ite->second.got_clicked(localPosition.x, localPosition.y))
					{
						if(ite->first == "start")
						{
							m_game = new Game(m_window.getSize().x, m_window.getSize().y - 100, &m_player);
							m_state = SGame;
						}
						else if(ite->first == "quit")
							m_window.close();
					}
				}
			}
			
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
		
		if(m_state == SGame)
		{
        	m_game->progress();
		}

        // Draw
        refresh_screen();
        
        m_window.display();
    }
}