#pragma once
#include "BoardReader.h"
#include <vector>

using std::vector;

class Board {
public:
	Board();

	int getSize();
	void loadMap();
private:
	BoardReader m_boardReader;
	vector<vector<char>> m_map;
};