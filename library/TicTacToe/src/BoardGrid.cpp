#include "BoardGrid.hpp"

namespace tictactoe {
BoardGrid::BoardGrid() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = Cell::EMPTY;
		}
	}
}

BoardGrid::BoardGrid(BoardGrid &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = other.getCell(i, j);
		}
	}
}

Cell BoardGrid::getCell(int x, int y) {
	return board[x][y];
}

void BoardGrid::setCell(int x, int y, Cell c) {
	board[x][y] = c;
}
} // namespace TicTacToe
