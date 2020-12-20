/* BoardReader.cpp
 * ===========================================================================
 */
 //=========================== include section ===============================
#include "BoardReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include <iostream>
#include <fstream>

//========================== constractors section ============================
/*============================================================================
 * The constractor is open the levels file and then the file reader
 * is waiting to load the first stage.
 * input: none.
 * output: none.
*/
BoardReader::BoardReader(){
	this->m_boardReader.open(BOARD_PATH);
	if (!this->m_boardReader.is_open()) {
		std::ofstream creator;
		creator.open(BOARD_PATH);
		if (!(creator.is_open()))
			terminate("Unable to create Board.txt file!");
		this->m_boardReader.open(BOARD_PATH);
		if (!this->m_boardReader.is_open())
			terminate("Board.txt file opening failure");
		creator.close();
	}
	this->calcMapSize();
}
//============================================================================
BoardReader::~BoardReader() {
	this->m_boardReader.close();
}
//============================ methods section ===============================
/*============================================================================
 * The method reading the level from the Board.txt file.
 * input: none.
 * output: readed map.
*/
std::vector<std::vector<char>> BoardReader::readLevel() {
	std::vector<std::vector<char>> map = {};
	int formerLoc = (int)this->m_boardReader.tellg();
	
	if (this->m_boardReader.peek() == EOF) {
		for (int i = 0; i < this->m_mapSize.x; ++i) {
			std::vector<char> row = {};
			for (int j = 0; j < this->m_mapSize.y; ++j)
				row.push_back(NOTHING);
			map.push_back(row);
		}
		return map;
	}

	//skip line of size defanition
	std::string receivedLine;
	this->m_boardReader >> receivedLine >> receivedLine;
	this->m_boardReader.get();
	
	//reset map's cols
	for (int i = 0; i < this->m_mapSize.x; ++i)
		map.push_back({});
	
	//reading the map.
	char receivedChar;
	for (int y = 0; y < this->m_mapSize.y; ++y) {
		for (int x = 0; x < this->m_mapSize.x; ++x) {
			this->m_boardReader.get(receivedChar);
			switch (receivedChar)
			{
			case PLAYER:
				map[x].push_back(PLAYER);
				break;
			case ENEMY:
				map[x].push_back(ENEMY);
				break;
			case WALL:
				map[x].push_back(WALL);
				break;
			case NOTHING:
				map[x].push_back(NOTHING);
				break;
			case LADDER:
				map[x].push_back(LADDER);
				break;
			case ROD:
				map[x].push_back(ROD);
				break;
			case COIN:
				map[x].push_back(COIN);
				break;
			default:
				std::string errorMessage = "receiving the char ";
				errorMessage.append(1, receivedChar);
				errorMessage.append(" not declered!");
				terminate(errorMessage);
				break;
			}
		}
		if (this->m_boardReader.peek() != '\0')
			this->m_boardReader.get();
	}
	//return the ifstream to the received location.
	this->m_boardReader.seekg(formerLoc);
	return map;
}
//============================================================================
void BoardReader::saveMap(const std::vector<std::vector<char>> &map) {
	std::ofstream writer;
	writer.open(BOARD_PATH);
	if (!writer.is_open())
		terminate("board saving failure!");
	//print map size
	writer << (int)map[0].size() << ' ' << (int)map.size() << std::endl;
	//print map
	for (int y = 0; y < map[0].size(); ++y) {
		for (int x = 0; x < map.size(); ++x) {
			char temp = map[x][y];
			writer << map[x][y];
		}
		writer << std::endl;
	}
	writer << '\0';
	writer.close();
}
/*============================================================================
 * The method is calculate the map size by the demanded syntax
 * input: none.
 * output: none.
*/
void BoardReader::calcMapSize() {
	this->m_mapSize = sf::Vector2f(0, 0);
	if (this->m_boardReader.peek() != EOF)
		readMapSize();
	if(!this->mapsizeIsValid())
		this->receiveMapSize();
}
/*============================================================================
 * The method reading the map size from the Board.txt file.
 * input: none.
 * output: none.
*/
void BoardReader::readMapSize() {
	int firstLoc = (int)this->m_boardReader.tellg();
	this->m_boardReader.seekg(0);

	this->m_mapSize.x = 0;
	this->m_mapSize.y = 0;
	std::string charSize;
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		this->m_mapSize.y *= 10;
		this->m_mapSize.y += charSize[i] - '0';
	}
	this->m_boardReader >> charSize;
	for (int i = 0; i < charSize.size(); ++i) {
		if (!isdigit(charSize[i]))
			terminate("size receiving error!");
		this->m_mapSize.x *= 10;
		this->m_mapSize.x += charSize[i] - '0';
	}

	this->m_boardReader.seekg(firstLoc);
}
/*============================================================================
 * The method receive the map size from the user.
 * input: none.
 * output: none.
*/
void BoardReader::receiveMapSize() {
	while (true) {
		std::cout << "please enter wanted map height: ";
		std::cin >> this->m_mapSize.y;
		std::cout << "please enter wanted map width: ";
		std::cin >> this->m_mapSize.x;
		//check the received syntax.
		if (!this->mapsizeIsValid())
			std::cout << "invalid map size!\n";
		else
			break;
	}
}
/*============================================================================
 * The method is check if the map size is valid.
 * input: none.
 * output: if the map size is valid.
*/
bool BoardReader::mapsizeIsValid()const {
	bool intx = this->m_mapSize.x - (int)this->m_mapSize.x == 0;
	bool xval = this->m_mapSize.x != 0;
	bool inty = this->m_mapSize.y - (int)this->m_mapSize.y == 0;
	bool yval = this->m_mapSize.y != 0;
	return(this->m_mapSize.x == (int)this->m_mapSize.x &&
		this->m_mapSize.x != 0 &&
		this->m_mapSize.y == (int)this->m_mapSize.y &&
		this->m_mapSize.y != 0);
}