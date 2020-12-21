/* Utilities.cpp
 * ===========================================================================
 */
//=========================== include section ===============================
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "MessageWindow.h"
//========================================================================
/* The function print the received error message and close the program
 * with -1 return value.
 * input: string
 * output: none.
*/
void terminate(const std::string errorMessage) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}
//========================================================================
/* The function calc and return if the received click is in the 
 * received rectangle on the map.
 * input: string
 * output: none.
*/
bool isInRec(const sf::Vector2f& startLoc, const sf::Vector2f& size, 
	const sf::Vector2f& point) {
	return (point.x < startLoc.x ||
		point.x > startLoc.x + size.x ||
		point.y < startLoc.y ||
		point.y > startLoc.y + size.y);
}
/*============================================================================
 * The function receive leagle map size from the user and return it.
 * input: none.
 * output: received .
*/
sf::Vector2f receiveMapSize() {
	sf::Vector2f mapSize;
	MessageWindow message = MessageWindow(
		sf::Vector2f(MESSAGE_WIDTH, MESSAGE_HEIGHT),
		sf::Vector2f(MESSAGE_LOC_WIDTH, MESSAGE_LOC_HEIGHT),
		"Please enter map size in the console.", "map size receiving guid");
	message.displayMessage();
	while (true) {

		std::cout << "please enter wanted map height: ";
		std::cin >> mapSize.y;
		std::cout << "please enter wanted map width: ";
		std::cin >> mapSize.x;
		//check the received syntax.
		if (!mapSizeIsValid(mapSize))
			std::cout << "invalid map size!\n";
		else
			break;
	}
	message.closeMessage();
	return mapSize;
}
/*============================================================================
 * The function check if the map size is valid.
 * input: none.
 * output: if the map size is valid.
*/
bool mapSizeIsValid(const sf::Vector2f& mapSize){
	bool intx = mapSize.x - (int)mapSize.x == 0;
	bool xval = mapSize.x != 0;
	bool inty = mapSize.y - mapSize.y == 0;
	bool yval = mapSize.y != 0;
	return(mapSize.x == mapSize.x && mapSize.x != 0 &&
		mapSize.y == mapSize.y && mapSize.y != 0);
}