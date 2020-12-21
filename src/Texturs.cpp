/* Texture.cpp
 * ===========================================================================
 */
//=========================== include section ===============================
#include "Texturs.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Macros.h"
using std::cout;
//========================== constractors section ============================
Textures::Textures() : m_texturs({}){}
//============================== gets section ================================
int Textures::getSize()const {return (int)m_texturs.size();}
//============================ methods section ===============================
/*============================================================================
 * The method receive char and return the needed texture by the Macros 
 * declareations.
 * input: wanted texture by the macros decleration.
 * output: wanted texture.
*/
const sf::Texture& Textures::operator[](char c)const {
	switch (c)
	{
	case MENU:
		return this->m_texturs[0];
	case PLAYER: {
		return this->m_texturs[1];
	}
	case ENEMY: {
		return this->m_texturs[2];
	}
	case COIN: {
		return this->m_texturs[3];
	}
	case WALL: {
		return this->m_texturs[4];
	}
	case LADDER: {
		return this->m_texturs[5];
	}
	case ROD: {
		return this->m_texturs[6];
	}
	case DELETE: {
		return this->m_texturs[7];
	}
	case CLEAR: {
		return this->m_texturs[8];
	}
	case SAVE: {
		return this->m_texturs[9];
	}
	default: return this->m_texturs[0];
	}
}
/*============================================================================
 * The method receive the index and return which texture is in this texture.
 * input: index.
 * output: which txture is in the received index.
*/
char Textures::getSymbol(int index)const {
	switch (index)
	{
	case 0:
		return MENU;
	case 1: {
		return PLAYER;
	}
	case 2: {
		return ENEMY;
	}
	case 3: {
		return COIN;
	}
	case 4: {
		return WALL;
	}
	case 5: {
		return LADDER;
	}
	case 6: {
		return ROD;
	}
	case 7: {
		return DELETE;
	}
	case 8: {
		return CLEAR;
	}
	case 9: {
		return SAVE;
	}
	default: return MENU;
	}
}
/*============================================================================
 * The method add texture to the texture vecture from the file
 * input: tecture's file path.
 * output: none.
*/
void Textures::addTexture(const std::string address) {
	sf::Texture input_texture = sf::Texture();

	if (!input_texture.loadFromFile(address)) {
		cout << "Cannot load " << address << std::endl;
	}
	this->m_texturs.push_back(input_texture);
}
/*============================================================================
 * The method loading all the demanded textures
 * input: none.
 * output: none.
*/
void Textures::loadTextures() {
	this->m_texturs = {};

	addTexture("menu.png");

	addTexture("player.png");

	addTexture("enemy.png");

	addTexture("coin.png");

	addTexture("wall.png");

	addTexture("ladder.png");

	addTexture("rod.png");

	addTexture("eraser.png");

	addTexture("trash.png");

	addTexture("save.png");
}