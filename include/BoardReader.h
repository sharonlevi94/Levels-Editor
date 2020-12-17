#pragma once
//---------------------------- include section -------------------------------
#include <fstream>
#include <vector>
//------------------------------ using section -------------------------------
using std::ifstream;
/*----------------------------------------------------------------------------
 * BoardReader
 * The class is loading the Boards file, and return it's information by the
 * needed syntax.
*/
class BoardReader {
public:
	//------------------------- constractors section -------------------------
	BoardReader();

	//------------------------- method section -------------------------------
	std::vector < std::vector<char>> readNextLevel();
private:
	//--------------------- privete methods section --------------------------
	
	int receiveMapSize();

	//------------------------ members section -------------------------------
	int m_mapSize;
	ifstream m_boardReader;
};
