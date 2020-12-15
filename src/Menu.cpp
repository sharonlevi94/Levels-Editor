
#include "Menu.h"
#include <iostream>

Menu::Menu(int width,int height)
{
	if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
		std::cout << "error font";
		//handle error
	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Blue);
	menu[0].setString("Menu");
	menu[0].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS+1)*1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString(PLAYER);
	menu[1].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString(ENEMY);
	menu[2].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString(WALL);
	menu[3].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 4));

	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString(LADDER);
	menu[4].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 5));

	menu[5].setFont(font);
	menu[5].setColor(sf::Color::White);
	menu[5].setString(ROD);
	menu[5].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 6));

	menu[6].setFont(font);
	menu[6].setColor(sf::Color::White);
	menu[6].setString(COIN);
	menu[6].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 7));

	menu[7].setFont(font);
	menu[7].setColor(sf::Color::White);
	menu[7].setString("Delete");
	menu[7].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 8));

	menu[8].setFont(font);
	menu[8].setColor(sf::Color::White);
	menu[8].setString("Clean");
	menu[8].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 9));

	menu[9].setFont(font);
	menu[9].setColor(sf::Color::White);
	menu[9].setString("Save");
	menu[9].setPosition(sf::Vector2f(0, height / (MAX_NUM_OF_ITEMS + 1) * 10));

	selectedItemIndex = 1;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUM_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItemIndex - 1 >= 1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 < MAX_NUM_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
		 
	}
}

