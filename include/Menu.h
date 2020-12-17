#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Button.h"


class Menu
{
public:
	Menu(sf::Vector2f size, sf::Vector2f);

	void draw(sf::RenderWindow& window);
	char handleClick(sf::Vector2f click_location);
	
private:
	std::vector<Button> m_Buttons;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
};

