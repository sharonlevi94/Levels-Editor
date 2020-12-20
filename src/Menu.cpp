#include "Menu.h"
#include <iostream>
#include "Texturs.h"
#include "Utilities.h"
using std::cout;
//=============================================================================
Menu::Menu(sf::Vector2f size, sf::Vector2f position)
	: m_size(size), m_position(position),
	m_logoHeight(140),
	m_buttonHeight(0){
	if (MAX_NUM_OF_ITEMS != 0)
		this->m_buttonHeight = 
		(this->m_size.y - this->m_logoHeight) / MAX_NUM_OF_ITEMS;
}
//=============================================================================
void Menu::draw(sf::RenderWindow &window, const Textures& textures) const{
	sf::RectangleShape backGround;
	backGround.setSize(m_size);
	backGround.setFillColor(sf::Color::Blue);
	window.draw(backGround);

	sf::RectangleShape logo = 
		sf::RectangleShape(sf::Vector2f(this->m_size.x, this->m_logoHeight));
	//set texture receive the texture as const.
	logo.setTexture(&textures[MENU]);
	logo.setPosition(this->m_position);
	window.draw(logo);
	for (int i = 1; i < MAX_NUM_OF_ITEMS; ++i) {
		sf::RectangleShape button = sf::RectangleShape
		(sf::Vector2f(this->m_size.x, this->m_buttonHeight));
		button.setPosition
		(this->m_position.x, this->m_logoHeight + (this->m_buttonHeight * (i - 1)));
		button.setTexture(&textures[textures.getSymbol(i)]);
		button.setOutlineColor(sf::Color::White);
		button.setOutlineThickness(1);
		window.draw(button);
	}
}
//=============================================================================
char Menu::handleClick(const sf::Vector2f& clickLocation) const
{
	//making sure click is on menu
	if (isInRec(this->m_position, this->m_size, clickLocation))
		return NOTHING;

	if (clickLocation.y <= this->m_logoHeight)
		return NOTHING;
	int buttonNum = (int)((clickLocation.y - 
		(this->m_position.y + this->m_logoHeight)) / this->m_buttonHeight);

	switch (buttonNum)
	{
	case 0:
		return PLAYER;
	case 1:
		return ENEMY;
	case 2:
		return COIN;
	case 3:
		return WALL;
	case 4:
		return LADDER;
	case 5:
		return ROD;
	case 6:
		return DELETE;
	case 7:
		return CLEAR;
	case 8:
		return SAVE;
	default:
		break;
	}
	return NOTHING;
}
 
