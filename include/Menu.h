#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Button.h"
//=============================================================================
class Menu
{
public:
	Menu(sf::Vector2f size = sf::Vector2f(0,0), sf::Vector2f position = sf::Vector2f(0,0));

	void draw(sf::RenderWindow& window);
	sf::RectangleShape handleClick(const sf::Vector2f&);
	
private:
	std::vector<Button> m_Buttons;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
};

