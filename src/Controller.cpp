#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "iostream"
//=============================================================================
Controller::Controller() :
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ex4"),
	m_menu(Menu(sf::Vector2f((float)MENU_WIDTH, (float)MENU_HEIGHT), sf::Vector2f(0,0))),
	m_board(Board(sf::Vector2f((float)BOARD_WIDTH,(float)BOARD_HEIGHT),
		sf::Vector2f((float)MENU_WIDTH,0))) {}
//=============================================================================
void Controller::run() {

	while (this->m_window.isOpen())
	{
		this->m_window.clear();
		this->m_menu.draw(this->m_window);
		this->m_board.draw(this->m_window);
		this->m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased: 
			{
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if(location.x <= MENU_WIDTH)
					std::cout << "menu pressed\n";
				if (location.x > MENU_WIDTH)
					this->m_board.handleClick(location, NOTHING);
			}
			}
		}
	}
}