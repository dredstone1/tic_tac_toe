#include "Board.hpp"
#include <iostream>

namespace TicTacToe {
Board::Board() {}

void Board::draw() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "[" << (char)Grid.getCell(i, j) << "] ";
		}

		std::cout << std::endl;
	}
}

cell Board::get(int x, int y) {
	return Grid.getCell(x, y);
};

void Board::set(int x, int y, cell c) {
	Grid.setCell(x, y, c);
	UpdateBoardState();
}

void Board::UpdateBoardState() { boardState = ScanBoardState(Grid); }

BoardState Board::ScanBoardState(BoardGrid &Grid) {
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (Grid.getCell(i, 0) == Grid.getCell(i, 1) &&
		    Grid.getCell(i, 1) == Grid.getCell(i, 2)) {
			if (Grid.getCell(i, 0) == cell::X) {
				return BoardState::WinX;
			} else if (Grid.getCell(i, 0) == cell::O) {
				return BoardState::WinO;
			}
		}
	}

	// Check columns
	for (int i = 0; i < 3; i++) {
		if (Grid.getCell(0, i) == Grid.getCell(1, i) &&
		    Grid.getCell(1, i) == Grid.getCell(2, i)) {
			if (Grid.getCell(0, i) == cell::X) {
				return BoardState::WinX;
			} else if (Grid.getCell(0, i) == cell::O) {
				return BoardState::WinO;
			}
		}
	}

	// Check diagonals
	if (Grid.getCell(0, 0) == Grid.getCell(1, 1) &&
	    Grid.getCell(1, 1) == Grid.getCell(2, 2)) {
		if (Grid.getCell(0, 0) == cell::X) {
			return BoardState::WinX;
		} else if (Grid.getCell(0, 0) == cell::O) {
			return BoardState::WinO;
		}
	}

	// Check diagonals
	if (Grid.getCell(0, 2) == Grid.getCell(1, 1) &&
	    Grid.getCell(1, 1) == Grid.getCell(2, 0)) {
		if (Grid.getCell(0, 2) == cell::X) {
			return BoardState::WinX;
		} else if (Grid.getCell(0, 2) == cell::O) {
			return BoardState::WinO;
		}
	}

	// Check for draw
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Grid.getCell(i, j) == cell::EMPTY) {
				return BoardState::Continue;
			}
		}
	}

	// If no empty cells, return draw
	return BoardState::Draw;
}

} // namespace TicTacToe
