#include "Board.hpp"
#include <iostream>

using namespace std;

namespace TicTacToe {
Board::Board() {}

void Board::draw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[" << string(1, Grid.getCell(i, j)) << "] ";
    }
    cout << endl;
  }
}

cell Board::get(int x, int y) { return Grid.getCell(x, y); };

void Board::set(int x, int y, cell c) { Grid.setCell(x, y, c); }
} // namespace TicTacToe
