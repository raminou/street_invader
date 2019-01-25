#include "window.hh"

Window::Window(int size_window_x, int size_window_y):

    m_window(sf::VideoMode(size_window_x, size_window_y, sf::Style::Titlebar | sf::Style::Close), "Street Invaders"),
	m_state(SMenu),
    m_player(0, 0, Player::m_player_size, 0, "E.Macron"),
    m_game(nullptr),
    m_rect_player(sf::Vector2f(Player::m_player_size, Player::m_player_size)),
	m_banner_position(size_window_x),
	m_buttons_menu(std::map<std::string, Button>()),
	m_buttons_endgame(std::map<std::string, Button>()),
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
    

    if (!m_window_texture_background_game.loadFromFile("resources/texture/background_game.png")) {
    	std::cout << "Error loading background_game.png" << std::endl;
    }
    else {
	    m_window_sprite_background_game.setTexture(m_window_texture_background_game);
	    m_window_sprite_background_game.setScale(0.8f, 0.8f);
    }

    if (!m_window_texture_background_menu.loadFromFile("resources/texture/background_menu.jpg")) {
    	std::cout << "Error loading background_menu.jpg" << std::endl;
    }
    else {
	    m_window_sprite_background_menu.setTexture(m_window_texture_background_menu);
	    m_window_sprite_background_menu.setScale(0.75f, 0.75f);
    }

    if (!m_window_texture_background_lose.loadFromFile("resources/texture/background_lose.jpeg")) {
    	std::cout << "Error loading background_lose.jpeg" << std::endl;
    }
    else {
	    m_window_sprite_background_lose.setTexture(m_window_texture_background_lose);
	    m_window_sprite_background_lose.setScale(0.80f, 0.9f);
    }

    if (!m_window_texture_background_win.loadFromFile("resources/texture/background_win.png")) {
    	std::cout << "Error loading background_win.png" << std::endl;
    }
    else {
	    m_window_sprite_background_win.setTexture(m_window_texture_background_win);
	    m_window_sprite_background_win.setScale(0.43f, 0.48f);
    }

	// Buttons Menu
	m_buttons_menu["start"] = Button(250, 150, 100, 50, sf::Text());
	m_buttons_menu["quit"] = Button(250, 250, 100, 50, sf::Text());
	
	m_buttons_menu["start"].get_text().setString("Start");
	m_buttons_menu["start"].get_text().setFillColor(sf::Color::Red);
	if(std::get<0>(m_font_banner))
		m_buttons_menu["start"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons_menu["start"].get_text().setCharacterSize(50);
		
	m_buttons_menu["quit"].get_text().setString("Quit");
	m_buttons_menu["quit"].get_text().setFillColor(sf::Color::Red);
	if(std::get<0>(m_font_banner))
		m_buttons_menu["quit"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons_menu["quit"].get_text().setCharacterSize(50);
	
	// Buttons End Game
	m_buttons_endgame["restart"] = Button(10, 445, 200, 50, sf::Text());
	m_buttons_endgame["menu"] = Button(size_window_x - 90, 445, 200, 50, sf::Text());
		
	m_buttons_endgame["restart"].get_text().setString("Restart");
	m_buttons_endgame["restart"].get_text().setFillColor(sf::Color(255, 140, 0));
	if(std::get<0>(m_font_banner))
		m_buttons_endgame["restart"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons_endgame["restart"].get_text().setCharacterSize(30);
		
	m_buttons_endgame["menu"].get_text().setString("Menu");
	m_buttons_endgame["menu"].get_text().setFillColor(sf::Color(255, 140, 0));
	if(std::get<0>(m_font_banner))
		m_buttons_endgame["menu"].get_text().setFont(std::get<1>(m_font_banner));
	m_buttons_endgame["menu"].get_text().setCharacterSize(30);
}

void Window::refresh_screen()
{
	sf::RectangleShape rect_tmp;
	sf::Sprite sprite;
	sf::Text title;
	sf::Text subtitle;
	sf::Text stats1;
	sf::Text stats2;
	sf::Text stats3;
	
	switch(m_state) {
		case SGame:

			//Background
			sprite = m_window_sprite_background_game;
    		m_window_sprite_background_game.setPosition(0, 0);
    		m_window.draw(m_window_sprite_background_game);

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

			sprite = m_window_sprite_background_menu;
    		m_window_sprite_background_menu.setPosition(0, 0);
    		m_window.draw(m_window_sprite_background_menu);

			if(std::get<0>(m_font_banner))
				title.setFont(std::get<1>(m_font_banner));

			title.setString("Street Invaders");
			title.setFillColor(sf::Color::Yellow);
			title.setCharacterSize(50);
			title.setPosition(250, 50);
			m_window.draw(title);

			for(std::map<std::string, Button>::iterator ite = m_buttons_menu.begin(); ite != m_buttons_menu.end(); ite++)
				ite->second.draw(m_window);
			
			break;
		case SEndGame:
			// Title
			if(std::get<0>(m_font_banner))
				title.setFont(std::get<1>(m_font_banner));
			if(m_game->get_game_state() == PlayerWon)
			{
				sprite = m_window_sprite_background_win;
    			m_window_sprite_background_win.setPosition(0, 0);
    			m_window.draw(m_window_sprite_background_win);
/*
				title.setString("The democracy has been kept safe !");
				title.setFillColor(sf::Color::Blue);
				title.setPosition(50, 50);
*/
			}
			else
			{
				sprite = m_window_sprite_background_lose;
    			m_window_sprite_background_lose.setPosition(0, 0);
    			m_window.draw(m_window_sprite_background_lose);
    		}
				title.setString("Apres " + std::to_string(m_game->get_time()) + "h dans les rues et " + 
											std::to_string(m_game->get_nb_shot() * 100) + " euros de depense, " +
											std::to_string(m_player.get_score()) + " Gilets Jaunes repousses.");
				title.setFillColor(sf::Color::Black);
				title.setPosition(110, m_game->get_size_y() + 58);

			
			title.setCharacterSize(18);
			m_window.draw(title);
			
			// Subtitle
			if(std::get<0>(m_font_banner))
				subtitle.setFont(std::get<1>(m_font_banner));
	/*		
			if(m_game->get_game_state() == PlayerWon)
			{
				subtitle.setString("Good Job");
				subtitle.setFillColor(sf::Color::Red);
				subtitle.setPosition(285, 125);
			}
			else
			{
			
				subtitle.setString("Prepare yourself for the revolution");
				subtitle.setFillColor(sf::Color::Red);
				subtitle.setPosition(200, 125);
			
			}
			subtitle.setCharacterSize(35);
			m_window.draw(subtitle);
	*/
/*			
			// Stats1
			if(std::get<0>(m_font_banner))
				stats1.setFont(std::get<1>(m_font_banner));
			stats1.setString(std::to_wstring(m_player.get_score()) + L" Gilets Jaunes repoussés");
			stats1.setFillColor(sf::Color::Red);
			stats1.setPosition(200, 200);
			stats1.setCharacterSize(35);
			m_window.draw(stats1);
			
			// Stats2
			if(std::get<0>(m_font_banner))
				stats2.setFont(std::get<1>(m_font_banner));
			stats2.setString(std::to_wstring(m_game->get_nb_shot() * 100) + L" € de dépense");
			stats2.setFillColor(sf::Color::Red);
			stats2.setPosition(250, 275);
			stats2.setCharacterSize(35);
			m_window.draw(stats2);
			
			// Stats3
			if(std::get<0>(m_font_banner))
				stats3.setFont(std::get<1>(m_font_banner));
			stats3.setString(std::to_wstring(m_game->get_time()) + L"h dans la rue");
			stats3.setFillColor(sf::Color::Red);
			stats3.setPosition(250, 350);
			stats3.setCharacterSize(35);
			m_window.draw(stats3);
*/			
			// Buttons
			for(std::map<std::string, Button>::iterator ite = m_buttons_endgame.begin(); ite != m_buttons_endgame.end(); ite++)
				ite->second.draw(m_window);
			break;
	}
}

void Window::display_info()
{
	// Score
	sf::Text text_score;
	if(std::get<0>(m_font_score))
		text_score.setFont(std::get<1>(m_font_score));
	
	text_score.setString("Opinion favorable : " + (std::to_string((m_player.get_score()) / 30)) + "%");
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(10, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	// Time
	sf::Text text_time;
	if(std::get<0>(m_font_score))
		text_score.setFont(std::get<1>(m_font_score));
	
	text_score.setString("Temps : " + std::to_string(m_game->get_time()) + "h");
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(800 - 120, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	// Banner
	sf::Text text_banner;
	if(std::get<0>(m_font_banner))
		text_banner.setFont(std::get<1>(m_font_banner));
	
	text_banner.setString(std::to_string(m_game->get_enemies().size() * 100) + " GILETS JAUNES ENCORE DANS LES RUES.\nEMMANUEL MACRON SUR LE TERRAIN POUR LES ARRETER.");
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
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(m_window);
				
				if(m_state == SMenu)
				{
					for(std::map<std::string, Button>::iterator ite = m_buttons_menu.begin(); ite != m_buttons_menu.end(); ite++)
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
				else if(m_state == SEndGame)
				{
					for(std::map<std::string, Button>::iterator ite = m_buttons_endgame.begin(); ite != m_buttons_endgame.end(); ite++)
					{
						if(ite->second.got_clicked(localPosition.x, localPosition.y))
						{
							if(ite->first == "restart")
							{
								delete m_game;
								m_game = new Game(m_window.getSize().x, m_window.getSize().y - 100, &m_player);
								m_player.sub_score(m_player.get_score());
								m_state = SGame;
							}
							else if(ite->first == "menu")
							{
								delete m_game;
								m_state = SMenu;
							}
						}
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
			if(m_game->get_game_state() != Unfinished)
				m_state = SEndGame;
		}

        // Draw
        refresh_screen();
        
        m_window.display();
    }
}