#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Button.h"
#include "Texturs.h"
//=============================================================================
class Menu
{
public:
	Menu(sf::Vector2f size = sf::Vector2f(0,0), 
		 sf::Vector2f position = sf::Vector2f(0,0));

	void draw(sf::RenderWindow& window, const Texturs&)const;
	char handleClick(const sf::Vector2f&)const;
	sf::RectangleShape createShape() const;
	
private:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	float m_buttonHeight;
};

