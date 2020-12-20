#pragma once
//============================ include section ===============================
#include "BoardReader.h"
#include "Texturs.h"
#include <vector>
#include <SFML/Graphics.hpp>
/*============================================================================
 * Board
 * the calss is responsible for the map drawing updating and saving.
*/
class Board {
public:
	//========================= constractors section =========================

	Board(const sf::Vector2f& size = sf::Vector2f(0, 0),
		  const sf::Vector2f& loc = sf::Vector2f(0, 0));
	//============================= gets section =============================

	int getHeight()const;
	int getWidth()const;
	//========================= method section ===============================

	void draw(sf::RenderWindow& window, const Textures& textures)const;
	void handleClick(const sf::Vector2f& clicLoc, char clickType);
	void saveMap();
	void clearMap();
private:
	//===================== privete methods section ==========================

	void loadMap();
	//======================== members section ===============================

	sf::Vector2f playerLoc;
	sf::Vector2f m_boardSize;
	sf::Vector2f m_startLoc;
	BoardReader m_boardReader;
	std::vector<std::vector<char>> m_map;
};