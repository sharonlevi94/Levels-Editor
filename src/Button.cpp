#include "Button.h"
Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Texture texture) {
	m_size = size;
	m_position = position;
	m_texture = texture;

}

void Button::drawButton(sf::RenderWindow& window) {
	sf::RectangleShape rec(m_size);
	rec.setTexture(&m_texture);
	rec.setPosition(m_position);

	if (this->m_size.x == 100) {
		rec.setOutlineColor(sf::Color::White);
		rec.setOutlineThickness(3);
	}
	window.draw(rec);
}
