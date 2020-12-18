#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"

class Controller {
public:
	Controller();

	void run();
private:
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
};
