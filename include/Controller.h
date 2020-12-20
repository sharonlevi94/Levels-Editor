#pragma once
//=========================== include section ===============================
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"
#include "Texturs.h"
/*============================================================================
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class Controller {
public:
	//========================= constractors section =========================
	Controller();

	void run();
private:
	Textures m_texturs;
	sf::RenderWindow m_window;
	Menu m_menu;
	Board m_board;
};
