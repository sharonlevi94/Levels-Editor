#include "Menu.h"
#include "Button.h"
#include <iostream>
#include "Texturs.h"
using std::cout;
//=============================================================================
Menu::Menu(sf::Vector2f size, sf::Vector2f position)
	: m_size(size), m_position(position)
{
	//set the title texture of the Menu:
	Button newButton(sf::Vector2f(140, 80),
		sf::Vector2f(size.x/12,0));
	m_Buttons.push_back(newButton);

	newButton=Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6, size.y / (MAX_NUM_OF_ITEMS) * 1));
	m_Buttons.push_back(newButton);   

	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 2), texture);
	m_Buttons.push_back(newButton);

	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 3), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 4), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 5), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6, size.y / (MAX_NUM_OF_ITEMS) * 6), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 7), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 8), texture);
	m_Buttons.push_back(newButton);

	
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 9), texture);
	m_Buttons.push_back(newButton);

}
//=============================================================================
void Menu::draw(sf::RenderWindow &window) {

	sf::RectangleShape backGround;
	backGround.setSize(m_size);
	backGround.setFillColor(sf::Color::Blue);

	window.draw(backGround);
	for (int i = 0; i < m_Buttons.size(); i++) {
		m_Buttons[i].drawButton(window);
	}
}
//=============================================================================
sf::RectangleShape Menu::handleClick(const sf::Vector2f& clickLocation)
{
	auto i=size_t(0);
	for (i = size_t(0); i < m_Buttons.size() ; ++i)
	{
		if (m_Buttons[i].createShape().getGlobalBounds().contains(clickLocation))
			return m_Buttons[i].createShape();
	}
	return m_Buttons[i].createShape();
}
 
