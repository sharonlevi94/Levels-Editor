/* Controller.cpp
 * ===========================================================================
 */
//=========================== include section ===============================
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Menu.h"
#include "Board.h"
#include "iostream"
#include "Texturs.h"
//========================== constractors section ============================
Controller::Controller() :
	m_board(Board(sf::Vector2f((float)BOARD_WIDTH, (float)BOARD_HEIGHT),
		sf::Vector2f((float)MENU_WIDTH, 0))),
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ex4"),
	m_menu(Menu(sf::Vector2f((float)MENU_WIDTH,(float)MENU_HEIGHT),
		sf::Vector2f(0, 0))),
	m_texturs(Textures()),
	m_clickMode(NOTHING){}
//============================ methods section ===============================
/*============================================================================
 * The method is running the app.
 * input: none.
 * output: none.
*/
void Controller::run() {
	/*loading the texture after window display because else receiving error 
	  message.
	*/
	this->m_window.clear();
	this->m_window.display();
	this->m_texturs.loadTextures();
	while (this->m_window.isOpen())
	{
		//draw state
		this->m_window.clear();
		this->draw();
		this->m_window.display();

		//calc click
		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased: 
			{
				auto location = m_window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });
				if (location.x <= MENU_WIDTH) {
					char choose = this->m_menu.handleClick(location);
					switch (choose)
					{
					case NOTHING:
						break;
					case CLEAR:
						this->m_board.clearMap();
						break;
					case SAVE:
						this->m_board.saveMap();
						break;
					default:
						this->m_clickMode = choose;
						break;
					}
				}
				else
					this->m_board.handleClick(location, this->m_clickMode);
			}
			}
		}
	}
}
/*============================================================================
 * The method is draw all the Console's objects.
 * input: none.
 * output: none.
*/
void Controller::draw() {
	//draw menu
	this->m_menu.draw(this->m_window, this->m_texturs);
	//draw board
	this->m_board.draw(this->m_window, this->m_texturs);
	//draw mouse texture if needed
	if (this->m_clickMode != NOTHING) {
		sf::RectangleShape mouseTexture = sf::RectangleShape(
			sf::Vector2f(100, 100));
		mouseTexture.setTexture(&this->m_texturs[this->m_clickMode]);
		mouseTexture.setPosition(static_cast<sf::Vector2f>
			(sf::Mouse::getPosition(this->m_window)));
		mouseTexture.setFillColor(sf::Color(255, 255, 255, 100));
		this->m_window.draw(mouseTexture);
	}

}