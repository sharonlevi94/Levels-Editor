
//This is a general functions that help us to execute the game.
#include <stdlib.h>
#include <iostream>
#include "Utilities.h"
//========================================================================
/* The function print the received error message and close the program
* with -1 return value.
 * input: string
 * output: none.
*/
void terminate(const char errorMessage[]) {
	std::cerr << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}