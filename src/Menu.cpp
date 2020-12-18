#include "Menu.h"
#include "Button.h"
#include <iostream>
using std::cout;
//=============================================================================
Menu::Menu() {}
Menu::Menu(sf::Vector2f size, sf::Vector2f position)
	: m_size(size), m_position(position)
{
	sf::Texture texture;

	if (!texture.loadFromFile("menu.png")) {
		cout << "Cannot load menu.png\n";
	}
	Button newButton(sf::Vector2f(140, 80),
		sf::Vector2f(size.x/12,0), texture);
	m_Buttons.push_back(newButton);
	
	if (!texture.loadFromFile("player.png")) {
		cout << "Cannot load player.png\n";
	}
	newButton=Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6, size.y / (MAX_NUM_OF_ITEMS) * 1), texture);
	m_Buttons.push_back(newButton);   

	if (!texture.loadFromFile("enemy.png")) {
		cout << "Cannot load enemy.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 2), texture);
	m_Buttons.push_back(newButton);


	if (!texture.loadFromFile("coin.png")) {
		cout << "Cannot load coin.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 3), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("wall.png")) {
		cout << "Cannot load wall.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 4), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("ladder.png")) {
		cout << "Cannot load ladder.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 5), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("rod.png")) {
		cout << "Cannot load rod.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6, size.y / (MAX_NUM_OF_ITEMS) * 6), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("eraser.png")) {
		cout << "Cannot load eraser.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 7), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("trash.png")) {
		cout << "Cannot load trash.png\n";
	}
	newButton = Button(sf::Vector2f(100, 80),
		sf::Vector2f(size.x / 6,  size.y / (MAX_NUM_OF_ITEMS) * 8), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("save.png")) {
		cout << "Cannot load save.png\n";
	}
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
	for (auto i = size_t(0); i < m_Buttons.size() ; ++i)
	{
		if (m_Buttons[i].createShape().getGlobalBounds().contains(clickLocation))
			return m_Buttons[i].createShape();
	}
}
 
