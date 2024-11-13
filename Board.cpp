#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = EMPTY;
    }
  }
}

void Board::draw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[" << string(1, get(i, j)) << "] ";
    }
    cout << endl;
  }
}

cell Board::get(int x, int y) {
  return board[x][y];
}

void Board::set(int x, int y, cell c) { 
    board[x][y] = c; 
}
