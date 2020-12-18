#include "Board.h"
#include "BoardReader.h"
#include <SFML/Graphics.hpp>
//============================================================================
Board::Board(const sf::Vector2f& size, const sf::Vector2f& loc) :
	m_boardReader(BoardReader()),
	m_boardSize(size),
	m_startLoc(loc),
	m_map(m_boardReader.readLevel()){}
//============================================================================
int Board::getSize() const{ return this->m_boardReader.getSize(); }
//============================================================================
void Board::loadMap() { this->m_map = this->m_boardReader.readLevel(); }
//============================================================================
void Board::draw(sf::RenderWindow &window)const {
	sf::RectangleShape backGround = sf::RectangleShape(this->m_boardSize);
	backGround.setFillColor(sf::Color(220, 226, 232, 255));
	backGround.setPosition(this->m_startLoc);
	window.draw(backGround);

	sf::Vector2f boxSize = sf::Vector2f(
		this->m_boardSize.x/this->getSize(), 
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