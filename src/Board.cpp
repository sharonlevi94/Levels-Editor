

#include "Board.h"
#include "BoardReader.h"

Board::Board()
	: m_boardReader(BoardReader()) {}

int Board::getSize() { return this->m_boardReader.getSize(); }