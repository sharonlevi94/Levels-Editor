#include "Button.h"
Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Texture texture) {
	m_size = size;
	m_position = position;
	m_texture = texture;
}


void Button::drawButton(sf::RenderWindow& window) {
	sf::Sprite ButtonSprite;
	ButtonSprite.setTexture(m_texture);
	ButtonSprite.setPosition(m_position);
	window.draw(ButtonSprite);
}