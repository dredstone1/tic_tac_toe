#ifndef BOARDGRID_HPP
#define BOARDGRID_HPP

namespace TicTacToe {
enum class cell {
	X = 'X',
	O = 'O',
	EMPTY = ' ',
};

class BoardGrid {
  private:
	cell board[3][3];

  public:
	BoardGrid();
	BoardGrid(BoardGrid &other);
	cell getCell(int x, int y);
	void setCell(int x, int y, cell c);
};
} // namespace TicTacToe
#endif
