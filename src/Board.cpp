#include "Board.h"
#include "BoardReader.h"
#include "Macros.h"
#include <iostream>
#include <SFML/Graphics.hpp>
//============================================================================
Board::Board(const sf::Vector2f& size, const sf::Vector2f& loc) :
	m_boardReader(BoardReader()),
	m_boardSize(size),
	m_startLoc(loc),
	m_map(m_boardReader.readLevel()),
	playerLoc(sf::Vector2f(-1,-1)){}
//============================================================================
int Board::getSize() const{ return this->m_boardReader.getSize(); }
//============================================================================
void Board::loadMap() { 
	this->m_map = this->m_boardReader.readLevel(); 
	for(int i = 0; i < this->getSize(); ++i)
		for (int j = 0; j < this->getSize(); ++j)
			if(this->m_map[i][j] == PLAYER){
				this->playerLoc = sf::Vector2f((float)i,(float)j);
				return;
			}
}

//============================================================================
void Board::handleClick(const sf::Vector2f& clicLoc, char clickType) {
	//check board exception:
	if (clicLoc.x < this->m_startLoc.x ||
		clicLoc.x > this->m_startLoc.x + this->m_boardSize.x)
		return;
	//calculate the location of the click:
	int x = (int)((clicLoc.x - this->m_startLoc.x)/ (this->m_boardSize.x / this->getSize()));
	int y = (int)((clicLoc.y - this->m_startLoc.y) / (this->m_boardSize.y / this->getSize()));
	this->m_map[x][y] = clickType;

	if (clickType == PLAYER) {
		if(this->playerLoc == sf::Vector2f(-1,-1))
			this->m_map[(int)this->playerLoc.x][(int)this->playerLoc.y] = NOTHING;
		this->playerLoc = sf::Vector2f((float)x, (float)y);
	}
	std::cout << "received click at:\nrow: " << x << " col: " << y << std::endl;
}
//============================================================================
void Board::saveMap() { this->m_boardReader.saveMap(this->m_map); }
//============================================================================
void Board::draw(sf::RenderWindow& window)const {
	sf::RectangleShape backGround = sf::RectangleShape(this->m_boardSize);
	backGround.setFillColor(sf::Color(220, 226, 232, 255));
	backGround.setPosition(this->m_startLoc);
	window.draw(backGround);

	sf::Vector2f boxSize = sf::Vector2f(
		this->m_boardSize.x / this->getSize(),
		this->m_boardSize.y / this->getSize());

	for (int i = 0; i < this->getSize(); ++i) {
		for (int j = 0; j < this->getSize(); ++j) {
			sf::RectangleShape box = sf::RectangleShape(boxSize);
			box.setPosition(this->m_startLoc.x + (boxSize.x * i),
				this->m_startLoc.y + (boxSize.y * j));
			box.setOutlineColor(sf::Color::Black);
			box.setOutlineThickness(1);
			box.setFillColor(sf::Color(220, 226, 232, 255));
			window.draw(box);
		}
	}
}