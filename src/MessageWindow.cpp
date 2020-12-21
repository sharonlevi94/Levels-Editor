/* MessageWindow.cpp
 * ===========================================================================
 */
 //=========================== include section ===============================
#include "MessageWindow.h"
#include <SFML/Graphics.hpp>
#include <iostream> //for string
#include "Macros.h"

//========================== constractors section ============================
MessageWindow::MessageWindow(const sf::Vector2f& size,
	const sf::Vector2f& location, const std::string& message, 
	const std::string& topic):
	m_location(location),
	m_message(message),
	m_window(sf::VideoMode((int)size.x,(int)size.y), topic){}
//============================================================================
MessageWindow::~MessageWindow() {
	if(this->m_window.isOpen())
		this->closeMessage();
}
//============================ methods section ===============================
/*============================================================================
 * The method is display the massage window.
 * input: none.
 * output: none.
*/
void MessageWindow::displayMessage() {
	sf::Font font;
	font.loadFromFile("ARIALBD.TTF");
	sf::Text text;
	this->m_window.clear(sf::Color(220, 226, 232, 255));
	text.setString(this->m_message);
	text.setColor(sf::Color::Black);
	text.setFont(font);
	this->m_window.draw(text);
	this->m_window.display();
}
/*============================================================================
 * The method is closing the message window.
 * input: none.
 * output: none.
*/
void MessageWindow::closeMessage() {
	this->m_window.close();
}