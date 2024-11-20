#ifndef BOARD_HPP
#define BOARD_HPP

#include "BoardGrid.hpp"

enum BoardState { WinX, WinO, Draw, Continue };

namespace TicTacToe {
class Board {
private:
  void UpdateBoardState();
  static BoardState ScanBoardState(BoardGrid &Grid);
  BoardState boardState = Continue;
  BoardGrid Grid;

public:
  Board();
  void draw();
  cell get(int x, int y);
  void set(int x, int y, cell c);
  BoardState GetBoardState() { return boardState; }
};
} // namespace TicTacToe

#endif
