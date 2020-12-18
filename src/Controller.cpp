#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Menu.h"
#include "Board.h"

Controller::Controller() :
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ex4"),
	m_menu(Menu(sf::Vector2((float)MENU_WIDTH, (float)MENU_HEIGHT))),
	m_board(Board()) {}

void Controller::run() {

	while (this->m_window.isOpen())
	{
		this->m_window.clear();
		this->m_menu.draw(this->m_window);
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
				//if(this->m_menu.handleClick(location) == OUT_RANGE_CLICK);
				break;
			}
			}
		}
	}
}