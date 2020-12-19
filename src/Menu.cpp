#include "Menu.h"
#include <iostream>
#include "Texturs.h"
using std::cout;
//=============================================================================
Menu::Menu(sf::Vector2f size, sf::Vector2f position)
	: m_size(size), m_position(position){
	if (MAX_NUM_OF_ITEMS != 0)
		this->buttonHeight = (this->m_size.y - logoHeight) / MAX_NUM_OF_ITEMS;
}
//=============================================================================
void Menu::draw(sf::RenderWindow &window, const Texturs& textures) const{
	float logoHeight = 140,
		logoWidth = 80,
		buttonHeight;


	//sf::RectangleShape backGround;
	//backGround.setSize(m_size);
	//backGround.setFillColor(sf::Color::Blue);

	sf::RectangleShape menu = sf::RectangleShape(sf::Vector2f(this->m_size.x, logoHeight));
	//set texture receive the texture as const.
	menu.setTexture(&textures[MENU]);
	menu.setPosition(this->m_position);
	menu.setFillColor(sf::Color::Blue);
	window.draw(menu);
	for (int i = 0; i < MAX_NUM_OF_ITEMS; ++i) {
		sf::RectangleShape button = sf::RectangleShape
		(sf::Vector2f(this->m_size.x, buttonHeight));
		button.setPosition(this->m_position.x, buttonHeight * i);
		button.setFillColor(sf::Color::Blue);
		//button.setTexture();
		button.setOutlineColor(sf::Color::White);
		button.setOutlineThickness(1);
	}
}
//=============================================================================
sf::RectangleShape Menu::handleClick(const sf::Vector2f& clickLocation)
{
	int buttonNum = this;

	auto i=size_t(0);
	for (i = size_t(0); i < m_Buttons.size() ; ++i)
	{
		if (m_Buttons[i].createShape().getGlobalBounds().contains(clickLocation))
			return m_Buttons[i].createShape();
	}
	return m_Buttons[i].createShape();
}
 
