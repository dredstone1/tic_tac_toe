#ifndef BOARDGRID_HPP
#define BOARDGRID_HPP

namespace tictactoe {
enum class Cell {
	X = 'X',
	O = 'O',
	EMPTY = ' ',
};

class BoardGrid {
  private:
	Cell board[3][3];

  public:
	BoardGrid();
	BoardGrid(BoardGrid &other);
	Cell getCell(int x, int y);
	void setCell(int x, int y, Cell c);
};
} // namespace tictactoe
#endif
