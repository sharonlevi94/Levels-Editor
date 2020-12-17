/* BoardReader
 * ===========================================================================
 */
 //---------------------------- include section -------------------------------
#include "BoardReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include <iostream>
#include <fstream>

//-------------------------- constractors section ----------------------------
/*----------------------------------------------------------------------------
 * The constractor is open the levels file and then the file reader
 * is waiting to load the first stage.
 * input: none.
 * output: none.
*/
BoardReader::BoardReader() {
	this->m_boardReader.open(BOARD_PATH);
	if (!(this->m_boardReader.is_open()))
		terminate("Unable to create Board.txt file!");
	this->m_mapSize = receiveMapSize();
}
//------------------------------ gets section --------------------------------
int BoardReader::getSize() { return this->m_mapSize; }

//---------------------------- methods section -------------------------------
/*----------------------------------------------------------------------------
 * The method read a new level from the file into a 2D vector.
 * input: None.
 * output: the new level as a map object.
*/
std::vector<std::vector<char>> BoardReader::readLevel() {
	std::vector<std::vector<char>> map;
	
	if (this->m_boardReader.peek() == '\0') {
		for (int i = 0; i < this->m_mapSize; ++i) {
			std::vector<char> row = {};
			for (int j = 0; j < this->m_mapSize; ++j)
				row.push_back(NOTHING);
			map.push_back(row);
		}
		return map;
	}

	int formerLoc = (int)this->m_boardReader.tellg();
	char receivedChar;
	if(this->m_boardReader.peek() == '\n')
		this->m_boardReader.get();
	for (int i = 0; i < this->m_mapSize; ++i) {
		std::vector<char> receivedMapRow = {};
		for (int j = 0; j < this->m_mapSize; ++j) {
			this->m_boardReader.get(receivedChar);
			switch (receivedChar)
			{
			case PLAYER:
				receivedMapRow.push_back(PLAYER);
				break;
			case ENEMY:
				receivedMapRow.push_back(ENEMY);
				break;
			case WALL:
				receivedMapRow.push_back(WALL);
				break;
			case NOTHING:
				receivedMapRow.push_back(NOTHING);
				break;
			case LADDER:
				receivedMapRow.push_back(LADDER);
				break;
			case ROD:
				receivedMapRow.push_back(ROD);
				break;
			case COIN:
				receivedMapRow.push_back(COIN);
				break;
			default:
				std::string errorMessage = "receiving the char ";
				errorMessage.append(1, receivedChar);
				errorMessage.append(" not declered!");
				terminate(errorMessage);
				break;
			}
		}
		if(this->m_boardReader.peek() != '\0')
			this->m_boardReader.get();
		map.push_back(receivedMapRow);
	}
	this->m_boardReader.seekg(formerLoc);
	return map;
}
/*----------------------------------------------------------------------------
 * The method is saving the received map into the file m_boardReader at.
 * input: map.
 * output: None.
*/
void BoardReader::saveMap(const std::vector<std::vector<char>> &map) {
	this->m_boardReader.seekg(0);
	this->m_boardReader << (int)map.size() << std::endl;
	for (int i = 0; i < this->m_mapSize; ++i) {
		for (int j = 0; j < this->m_mapSize; ++j)
			this->m_boardReader << map[i][j];
		this->m_boardReader << std::endl;
	}
}
/*----------------------------------------------------------------------------
 * The method check if the input size are a digits and what is the
 * size of the received map.
 * input: None
 * output: the size of the received map as an integer number.
*/
int BoardReader::receiveMapSize() {
	if (this->m_boardReader.peek() == '\0') {
		std::cout << "please enter wanted map size: ";
		std::cin >> this->m_mapSize;
		return this->m_mapSize;
	}

	int size = 0;
	std::string charSize;
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		size *= 10;
		size += charSize[i] - '0';
	}
	this->m_boardReader.get();//get /n
	return size;
}
