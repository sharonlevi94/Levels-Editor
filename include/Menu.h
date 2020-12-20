#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include <vector>
#include "Macros.h"
#include "Texturs.h"
/*============================================================================
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class Menu
{
public:
	//========================= constractors section =========================
	Menu(sf::Vector2f size = sf::Vector2f(0,0), 
		 sf::Vector2f position = sf::Vector2f(0,0));

	void draw(sf::RenderWindow& window, const Textures&)const;
	char handleClick(const sf::Vector2f&)const;
	
private:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	float m_buttonHeight, m_logoHeight;
};

