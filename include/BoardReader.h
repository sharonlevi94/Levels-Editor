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
private:
	//--------------------- privete methods section --------------------------
	
	int receiveMapSize();

	//------------------------ members section -------------------------------

	ifstream m_boardReader;
};
