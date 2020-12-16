#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Controller {
public:
	Controller();

	void run();
private:
	sf::RenderWindow m_window;
	Menu m_menu;
};
