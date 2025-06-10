#ifndef BOARD_HPP
#define BOARD_HPP

#include "BoardGrid.hpp"

namespace tictactoe {
enum class BoardState {
	WinX,
	WinO,
	Draw,
	Continue,
};

class Board {
  private:
	void UpdateBoardState();
	static BoardState ScanBoardState(BoardGrid &Grid);
	BoardState boardState = BoardState::Continue;
	BoardGrid Grid;

  public:
	Board();
	void draw();
	Cell get(int x, int y);
	void set(int x, int y, Cell c);
	BoardState GetBoardState() { return boardState; }
};
} // namespace tictactoe

#endif
