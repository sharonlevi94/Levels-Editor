#pragma once
#include <SFML/Graphics.hpp>

#define MAX_NUM_OF_ITEMS 10
#define PLAYER "@"
#define ENEMY "%"
#define LADDER "H"
#define ROD "-"
#define WALL "#"
#define COIN "*"


class Menu
{
public:
	Menu(int width,int height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUM_OF_ITEMS];
};

