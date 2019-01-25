#include "window.hh"

Window::Window(int size_window_x, int size_window_y):
	m_window(sf::VideoMode(size_window_x, size_window_y, sf::Style::Titlebar | sf::Style::Close), "Street Invaders"),
	m_state(SMenu),
	m_player(0, 0, Player::m_player_size, 0, "E.Macron"),
	m_game(nullptr),
	m_buttons_menu(std::map<std::string, Button>()),
	m_buttons_endgame(std::map<std::string, Button>()),
	m_font_score(sf::Font()),
	m_font_banner(sf::Font())
{
	m_window.setFramerateLimit(60);
	
	// Load font if it is possible
	if(!m_font_score.loadFromFile("resources/font/univers-condensed-bold.ttf"))
		std::cout << "Error loading font univers condensed bold font" << std::endl;
		
	// Load font if it is possible
	if(!m_font_banner.loadFromFile("resources/font/univers-condensed-bold.ttf"))
		std::cout << "Error loading font univers condensed bold font" << std::endl;
	
	// Load banner
	if (!m_window_texture_banner.loadFromFile("resources/texture/banner.png")) {
		std::cout << "Error loading banner.png" << std::endl;
	}
	else {
		m_window_sprite_banner.setTexture(m_window_texture_banner);
		m_window_sprite_banner.setScale(0.5f, 0.25f);
	}
	
	// Load background
	if (!m_window_texture_background_game.loadFromFile("resources/texture/background_game.png")) {
		std::cout << "Error loading background_game.png" << std::endl;
	}
	else {
		m_window_sprite_background_game.setTexture(m_window_texture_background_game);
		m_window_sprite_background_game.setScale(0.8f, 0.8f);
	}

	// Load background menu
	if (!m_window_texture_background_menu.loadFromFile("resources/texture/background_menu.jpg")) {
		std::cout << "Error loading background_menu.jpg" << std::endl;
	}
	else {
		m_window_sprite_background_menu.setTexture(m_window_texture_background_menu);
		m_window_sprite_background_menu.setScale(0.75f, 0.75f);
	}

	// Load background lose
	if (!m_window_texture_background_lose.loadFromFile("resources/texture/background_lose.jpeg")) {
		std::cout << "Error loading background_lose.jpeg" << std::endl;
	}
	else {
		m_window_sprite_background_lose.setTexture(m_window_texture_background_lose);
		m_window_sprite_background_lose.setScale(0.80f, 0.9f);
	}

	// Load background win
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
	
	// Start
	m_buttons_menu["start"].get_text().setString("Start");
	m_buttons_menu["start"].get_text().setFillColor(sf::Color::Red);
	m_buttons_menu["start"].get_text().setFont(m_font_banner);
	m_buttons_menu["start"].get_text().setCharacterSize(50);
	
	// Quit
	m_buttons_menu["quit"].get_text().setString("Quit");
	m_buttons_menu["quit"].get_text().setFillColor(sf::Color::Red);
	m_buttons_menu["quit"].get_text().setFont(m_font_banner);
	m_buttons_menu["quit"].get_text().setCharacterSize(50);
	
	// Buttons End Game
	m_buttons_endgame["restart"] = Button(10, 445, 200, 50, sf::Text());
	m_buttons_endgame["menu"] = Button(size_window_x - 90, 445, 200, 50, sf::Text());
	
	// Restart
	m_buttons_endgame["restart"].get_text().setString("Restart");
	m_buttons_endgame["restart"].get_text().setFillColor(sf::Color(255, 140, 0));
	m_buttons_endgame["restart"].get_text().setFont(m_font_banner);
	m_buttons_endgame["restart"].get_text().setCharacterSize(30);
	
	// Menu
	m_buttons_endgame["menu"].get_text().setString("Menu");
	m_buttons_endgame["menu"].get_text().setFillColor(sf::Color(255, 140, 0));
	m_buttons_endgame["menu"].get_text().setFont(m_font_banner);
	m_buttons_endgame["menu"].get_text().setCharacterSize(30);
}

void Window::refresh_screen()
{
	sf::RectangleShape rect_tmp;
	sf::Sprite sprite;
	sf::Text title;
	
	switch(m_state) {
		case SGame:
			/* Window state in Game */
			// Background
			sprite = m_window_sprite_background_game;
			m_window_sprite_background_game.setPosition(0, 0);
			m_window.draw(m_window_sprite_background_game);

			// Banner
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
			/* Window state in Menu */
			// Background
			sprite = m_window_sprite_background_menu;
			m_window_sprite_background_menu.setPosition(0, 0);
			m_window.draw(m_window_sprite_background_menu);
			
			// Title
			title.setFont(m_font_banner);
			title.setString("Street Invaders");
			title.setFillColor(sf::Color::Yellow);
			title.setCharacterSize(50);
			title.setPosition(250, 50);
			m_window.draw(title);

			// Buttons
			for(std::map<std::string, Button>::iterator ite = m_buttons_menu.begin(); ite != m_buttons_menu.end(); ite++)
				ite->second.draw(m_window);
			
			break;
		case SEndGame:
			/* Window state in End of game */
			// Title
			title.setFont(m_font_banner);
			if(m_game->get_game_state() == PlayerWon)
			{
				sprite = m_window_sprite_background_win;
    			m_window_sprite_background_win.setPosition(0, 0);
    			m_window.draw(m_window_sprite_background_win);
			}
			else
			{
				sprite = m_window_sprite_background_lose;
    			m_window_sprite_background_lose.setPosition(0, 0);
    			m_window.draw(m_window_sprite_background_lose);
    		}

			// Text
			title.setString(L"Après " + std::to_wstring(m_game->get_time()) + L"h dans les rues et " + 
										std::to_wstring(m_game->get_nb_shot() * 100) + L" euros de dépense, " + 
										std::to_wstring(m_player.get_score()) + L" Gilets Jaunes repoussés.");
			title.setFillColor(sf::Color::Black);
			title.setPosition(110, m_game->get_size_y() + 58);
			title.setCharacterSize(18);
			m_window.draw(title);
		
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
	text_score.setFont(m_font_score);
	text_score.setString("Opinion favorable : " + (std::to_string((m_player.get_score()) / 30)) + "%");
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(10, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	// Time
	sf::Text text_time;
	text_score.setFont(m_font_score);
	text_score.setString("Temps : " + std::to_string(m_game->get_time()) + "h");
	text_score.setCharacterSize(24);
	text_score.setFillColor(sf::Color::White);
	text_score.setPosition(800 - 120, m_game->get_size_y());
	text_score.setStyle(sf::Text::Bold);
	m_window.draw(text_score);
	
	// Banner
	sf::Text text_banner;
	text_banner.setFont(m_font_banner);
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
			// Clicked
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(m_window);
				
				if(m_state == SMenu)
				{
					// If we are in a menu, we look for which button has been clicked
					for(std::map<std::string, Button>::iterator ite = m_buttons_menu.begin(); ite != m_buttons_menu.end(); ite++)
					{
						if(ite->second.got_clicked(localPosition.x, localPosition.y))
						{
							// Action on click
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
					// If we are in the end of the game, we look for which button has been clicked
					for(std::map<std::string, Button>::iterator ite = m_buttons_endgame.begin(); ite != m_buttons_endgame.end(); ite++)
					{
						if(ite->second.got_clicked(localPosition.x, localPosition.y))
						{
							// Action on click
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
			
			// Key pressed only in game
			if(m_state == SGame)
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
								break;
							case sf::Keyboard::Right:
								m_game->player_move(RIGHT);
								break;
							case sf::Keyboard::Space:
								m_game->player_shot();
								break;
							default:
								break;
						}
						break;
					default:
						break;
				}
			}
		}

		m_window.clear();
		
		// If we are in game 
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