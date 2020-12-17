

#include "Board.h"
#include "BoardReader.h"

Board::Board()
	: m_boardReader(BoardReader()),
	m_map({}) {
	this->m_map = this->m_boardReader.readLevel();
}

int Board::getSize() { return this->m_boardReader.getSize(); }