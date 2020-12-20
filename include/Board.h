#pragma once
#include "BoardReader.h"
#include "Texturs.h"
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;

class Board {
public:
	Board(const sf::Vector2f& size = sf::Vector2f(0, 0),
		  const sf::Vector2f& loc = sf::Vector2f(0, 0));

	int getHeight()const;
	int getWidth()const;

	void draw(sf::RenderWindow& window, const Textures& textures)const;
	void handleClick(const sf::Vector2f& clicLoc, char clickType);
	void saveMap();
	void clearMap();
private:
	void loadMap();

	sf::Vector2f playerLoc;
	sf::Vector2f m_boardSize;
	sf::Vector2f m_startLoc;
	BoardReader m_boardReader;
	vector<vector<char>> m_map;
};