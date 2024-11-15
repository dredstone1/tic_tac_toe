#ifndef BOARD_HPP
#define BOARD_HPP

#include "BoardGrid.hpp"

namespace TicTacToe {
class Board {
public:
  Board();
  void draw();
  cell get(int x, int y);
  bool isFull();
  bool isWinner(char c);
  void set(int x, int y, cell c);

private:
  BoardGrid Grid;
};
} // namespace TicTacToe

#endif
