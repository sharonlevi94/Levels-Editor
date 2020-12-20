#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
//========================================================================
class Textures
{
public:
	Textures();
	const sf::Texture& operator[](char)const;
	int getSize()const;
	char getSymbol(int)const;
	void loadTextures();

private:
	void addTexture(const std::string);
	std::vector<sf::Texture> m_texturs;
};



