#pragma once
//=========================== include section ===============================
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"
#include "Texturs.h"
/*============================================================================
 * Controller
 * The class responsible to run the app and using the objects as needed.
*/
class Controller {
public:
	//========================= constractors section =========================
	Controller();
	//========================= method section ===============================

	void run();
private:
	//======================== members section ===============================

	Textures m_texturs;
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
};
