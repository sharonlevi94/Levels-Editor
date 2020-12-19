#pragma once
#include <SFML/Graphics.hpp>
class Button
{
public:
	Button(sf::Vector2f size,sf::Vector2f position);
	void drawButton(sf::RenderWindow& window);
	sf::RectangleShape createShape() const;

private:
	sf::Vector2f m_size;
	sf::Vector2f m_position;
	sf::Texture *m_texture;
};

