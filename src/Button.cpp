#include "Button.h"
//=============================================================================
Button::Button(sf::Vector2f size, sf::Vector2f position) {
	m_size = size;
	m_position = position;

}
//=============================================================================
void Button::drawButton(sf::RenderWindow& window) {
	
	if (this->m_size.x == 100) { //the rectangle include the title "menu"
		auto rec = createShape();
		rec.setOutlineColor(sf::Color::White);
		rec.setOutlineThickness(3);
	}
	window.draw(createShape());
}
//=============================================================================
sf::RectangleShape Button::createShape() const
{
	auto shape = sf::RectangleShape(m_size);
	shape.setTexture(&m_texture);
	shape.setPosition(m_position);
	return shape;
}
