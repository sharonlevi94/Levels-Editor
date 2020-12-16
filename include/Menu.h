#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Button.h"


class Menu
{
public:
	Menu(int width,int height);

	void draw(sf::RenderWindow& window);
	//char handleClick(sf::Vector2f click_location);
	
private:
	//int selectedItemIndex;
	//sf::Font font;
	//sf::Text menu[MAX_NUM_OF_ITEMS];
	//sf::Texture textures[MAX_NUM_OF_ITEMS];
	sf::Texture m_title;
	std::vector<Button> m_Buttons;
};

