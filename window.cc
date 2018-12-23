#include "window.hh"

Window::Window(int size_window_x, int size_window_y):
    m_window(sf::VideoMode(size_window_x, size_window_y), "TEST"),
    m_player(0, 0, 0, "toto"),
    m_game(nullptr)
{
    m_game = new Game(size_window_x, size_window_y, &m_player);
}

void Window::refresh_screen()
{
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
                            std::cout << "LEFT" << std::endl;
                            break;
                        case sf::Keyboard::Right:
                            std::cout << "Right" << std::endl;
                            break;
                        case sf::Keyboard::Space:
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

        // Draw
        m_window.display();
    }
}