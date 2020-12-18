#pragma once
#include "BoardReader.h"
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;

class Board {
public:
	Board(const sf::Vector2f& size = sf::Vector2f(0, 0), 
		const sf::Vector2f& loc = sf::Vector2f(0, 0));

	int getSize()const;

	void draw(sf::RenderWindow& window)const;
private:
	void loadMap();

	sf::Vector2f m_boardSize;
	sf::Vector2f m_startLoc;
	BoardReader m_boardReader;
	vector<vector<char>> m_map;
};