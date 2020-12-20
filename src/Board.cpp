/* Board.cpp
 * ===========================================================================
 */
//=========================== include section ===============================
#include "Board.h"
#include "BoardReader.h"
#include "Macros.h"
#include "Texturs.h"
#include "Utilities.h"
#include <iostream>
#include <SFML/Graphics.hpp>
//========================== constractors section ============================
Board::Board(const sf::Vector2f& size, const sf::Vector2f& loc) :
	m_boardReader(BoardReader()),
	m_boardSize(size),
	m_startLoc(loc),
	m_map({}),
	playerLoc(sf::Vector2f(-1,-1)){
	this->loadMap();
}
//============================= gets section =================================
//============================================================================
int Board::getHeight() const{ return (int)this->m_map[0].size(); }
//============================================================================
int Board::getWidth() const { return (int)this->m_map.size(); }
//============================================================================
//============================ methods section ===============================
/*============================================================================
 * The method is loading the map from the Board.txt file using the BoardReader
 * object.
 * input: none.
 * output: none.
*/
void Board::loadMap() { 
	this->m_map = this->m_boardReader.readLevel(); 
	for(int i = 0; i < this->getWidth(); ++i)
		for (int j = 0; j < this->getHeight(); ++j)
			if(this->m_map[i][j] == PLAYER){
				this->playerLoc = sf::Vector2f((float)i,(float)j);
				return;
			}
}
/*============================================================================
 * The method is locating which box in the net where clicked and change its
 * value to according the click value.
 * input: click location, the type of the click.
 * output: none.
*/
void Board::handleClick(const sf::Vector2f& clicLoc, char clickType) {
	//making sure the click is in board exception:
	if (isInRec(this->m_startLoc, this->m_boardSize, clicLoc))
		return;
	//calculate click's location:
	int x = (int)((clicLoc.x - this->m_startLoc.x)/ 
		(this->m_boardSize.x / this->getWidth()));
	int y = (int)((clicLoc.y - this->m_startLoc.y) / 
		(this->m_boardSize.y / this->getHeight()));
	//delete old player location and update the player location member:
	if (clickType == PLAYER) {
		if (this->playerLoc != sf::Vector2f(-1, -1))
			this->m_map[(int)this->playerLoc.x][(int)this->playerLoc.y] =
			NOTHING;
		this->playerLoc = sf::Vector2f((float)x, (float)y);
	}
	//change the clicked box value by the click type.
	if (clickType == DELETE)
		this->m_map[x][y] = NOTHING;
	else
		this->m_map[x][y] = clickType;
}
//============================================================================
void Board::saveMap() { this->m_boardReader.saveMap(this->m_map); }
/*============================================================================
 * The method change all the maps value to NOTHING value;
 * input: none.
 * output: none.
*/
void Board::clearMap() {
	for(int i = 0; i < this->getWidth(); ++i)
		for (int j = 0; j < this->getHeight(); ++j)
			this->m_map[i][j] = NOTHING;
}
//============================================================================
void Board::draw(sf::RenderWindow& window, const Textures& textures)const {
	//draw boxes background.
	sf::RectangleShape backGround = sf::RectangleShape(this->m_boardSize);
	backGround.setFillColor(sf::Color(220, 226, 232, 255));
	backGround.setPosition(this->m_startLoc);
	window.draw(backGround);

	//create box size by vector for prrogramming comfort
	sf::Vector2f boxSize = sf::Vector2f(
		this->m_boardSize.x / this->getWidth(),
		this->m_boardSize.y / this->getHeight());

	//drawing the map
	for (int i = 0; i < this->getWidth(); ++i) {
		for (int j = 0; j < this->getHeight(); ++j) {
			sf::RectangleShape box = sf::RectangleShape(boxSize);
			box.setPosition(this->m_startLoc.x + (boxSize.x * i),
				this->m_startLoc.y + (boxSize.y * j));
			box.setOutlineColor(sf::Color::Black);
			box.setOutlineThickness(1);
			if(this->m_map[i][j] != NOTHING)
				//textures passed as const so its safe.
				box.setTexture(&textures[this->m_map[i][j]]);
			window.draw(box);
		}
	}
}