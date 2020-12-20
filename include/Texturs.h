#pragma once
//============================ include section ===============================
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
/*============================================================================
 * Textures
 * The class is responsible for holding all the needed textures and give 
 * them to the needed objects.
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
	//======================== members section ===============================

	void addTexture(const std::string);
	std::vector<sf::Texture> m_texturs;
};



