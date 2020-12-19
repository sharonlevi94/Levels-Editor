#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"
#include "Texturs.h"
class Controller {
public:
	Controller();

	void run();
private:
	Texturs m_texturs;
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
};
