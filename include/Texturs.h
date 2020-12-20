#pragma once
//============================ include section ===============================
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
/*============================================================================
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class Textures
{
public:
	//========================= constractors section =========================

	Textures();

	//======================== operators section =============================

	const sf::Texture& operator[](char)const;

	//============================= gets section =============================

	int getSize()const;
	char getSymbol(int)const;
	void loadTextures();

private:
	void addTexture(const std::string);
	std::vector<sf::Texture> m_texturs;
};



