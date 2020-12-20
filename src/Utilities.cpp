//=========================== include section ===============================
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.h"
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

bool isInRec(const sf::Vector2f& startLoc, const sf::Vector2f& size, 
	const sf::Vector2f& point) {
	return (point.x < startLoc.x ||
		point.x > startLoc.x + size.x ||
		point.y < startLoc.y ||
		point.y > startLoc.y + size.y);
}