#pragma once
//============================ include section ===============================
#include <SFML/Graphics.hpp>
#include <iostream> //for string
#include "Macros.h"

/*============================================================================
 * MessageWindow
 * the class is an message window.
*/
class MessageWindow{
public:
	//========================= constractors section =========================

	MessageWindow(
		const sf::Vector2f& size = 
			sf::Vector2f(MESSAGE_WIDTH, MESSAGE_HEIGHT),
		const sf::Vector2f& location = 
			sf::Vector2f(MESSAGE_LOC_WIDTH, MESSAGE_LOC_HEIGHT),
		const std::string& message = "",
		const std::string& topic = "");

	~MessageWindow();
	//========================= method section ===============================

	void displayMessage();
	void closeMessage();
private:
	//======================== members section ===============================

	sf::RenderWindow m_window;
	sf::Vector2f m_location;
	std::string m_message;
};