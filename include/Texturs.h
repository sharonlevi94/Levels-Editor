#pragma once
#include <vector>
#include "Button.h"
class Texturs
{
public:
	Texturs();
	const sf::Texture& operator[](int)const;
	int getSize()const;

private:
	std::vector<sf::Texture> m_texturs;
};



