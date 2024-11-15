#include "../include/TicTacToe/game.hpp"
#include <iostream>

using namespace std;

namespace TicTacToe {

Game::Game() {}

void Game::run() {
    cout << "Start Game loop" << endl;
  Board b;
  b.set(1, 1, X);
  b.draw();

  return;
}
}

