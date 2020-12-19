#include "Texturs.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Macros.h"
using std::cout;
//===================================================================
Texturs::Texturs()
{
	sf::Texture input_texture;

	if (!input_texture.loadFromFile("menu.png")) {
		cout << "Cannot load menu.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("player.png")) {
		cout << "Cannot load player.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("enemy.png")) {
		cout << "Cannot load enemy.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("coin.png")) {
		cout << "Cannot load enemy.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("wall.png")) {
		cout << "Cannot load wall.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("ladder.png")) {
		cout << "Cannot load ladder.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("rod.png")) {
		cout << "Cannot load rod.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("eraser.png")) {
		cout << "Cannot load eraser.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("trash.png")) {
		cout << "Cannot load trash.png\n";
	}
	m_texturs.push_back(input_texture);

	if (!input_texture.loadFromFile("save.png")) {
		cout << "Cannot load trash.png\n";
	}
	m_texturs.push_back(input_texture);
}
//===================================================================
int Texturs::getSize()const {
	return m_texturs.size();
}
//===================================================================
const sf::Texture& Texturs::operator[](char c)const {
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
//===================================================================
char Texturs::getSymbol(int index)const {
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