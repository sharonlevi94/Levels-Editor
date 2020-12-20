#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Texturs.h"
/*============================================================================
 * Menu
 * the class is responsible for holding the buttons and tell wich of them
 * clicked on click situation.
*/
class Menu
{
public:
	//========================= constractors section =========================
	Menu(sf::Vector2f size = sf::Vector2f(0,0), 
		 sf::Vector2f position = sf::Vector2f(0,0));
	//========================= method section ===============================

	void draw(sf::RenderWindow& window, const Textures&)const;
	char handleClick(const sf::Vector2f&)const;
	
private:
	//======================== members section ===============================

	sf::Vector2f m_position;
	sf::Vector2f m_size;
	float m_buttonHeight, m_logoHeight;
};

