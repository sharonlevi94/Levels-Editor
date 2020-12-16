#include "Menu.h"
#include "Button.h"
#include <iostream>
using std::cout;
Menu::Menu(int width,int height)
{
	sf::Texture texture;

	if (!texture.loadFromFile("player.png")) {
		cout << "Cannot load player.png\n";
	}
	Button newButton(sf::Vector2f(10,10),
		sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS) * 1), texture);
	m_Buttons.push_back(newButton);

	if (!texture.loadFromFile("enemy.png")) {
		cout << "Cannot load player.png\n";
	}
	 newButton=Button(sf::Vector2f(10,10),
		sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS) * 2), texture);
	m_Buttons.push_back(newButton);
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < m_Buttons.size(); i++) {
		m_Buttons[i].drawButton(window);
	}
}
