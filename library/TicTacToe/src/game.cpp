#include "../include/TicTacToe/game.hpp"
#include "BoardGrid.hpp"
#include <iostream>

using namespace std;

namespace TicTacToe {

Game::Game(Player *playerX_, Player *playerO_)
    : playerO(EMPTY), playerX(EMPTY) {
  playerX.SetPlayer(playerX_, X);
  playerO.SetPlayer(playerO_, O);
}

void Game::run() {
  cout << "Start Game loop" << endl;
  Board b;
  b.draw();
  PlayerAdapter *currentPlayer = &playerX;

  while (b.GetBoardState() == Continue) {
    int move = currentPlayer->getMove();
    if (move < 0 || move > 8 || b.get(move / 3, move % 3) != EMPTY) {
      cout << "Invalid move" << endl;
      continue;
    }

    b.set(move / 3, move % 3, currentPlayer->getPlayerMode());
    b.draw();
    currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
  }

  switch (b.GetBoardState()) {
  case WinX:
    playerX.updateScore(playerX.getScore() + 1);
    playerX.UserWin();
    playerO.UserLost();
    break;
  case WinO:
    playerO.updateScore(playerO.getScore() + 1);
    playerO.UserWin();
    playerX.UserLost();
    break;
  case Draw:
    playerO.UserDraw();
    playerX.UserDraw();
    break;
  default:
    break;
  }
  return;
}
} // namespace TicTacToe
