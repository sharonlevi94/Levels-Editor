#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
//========================================================================
class Texturs
{
public:
	Texturs();
	const sf::Texture& operator[](char)const;
	int getSize()const;
	char getSymbol(int)const;

private:
	std::vector<sf::Texture> m_texturs;
};



