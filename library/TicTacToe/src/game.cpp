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
    b.set(move / 3, move % 3, currentPlayer->getPlayerMode());
    b.draw();
    currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
  }
  switch (b.GetBoardState()) {
  case WinX:
    cout << "Player X wins!" << endl;
    break;
  case WinO:
    cout << "Player O wins!" << endl;
    break;
  case Draw:
    cout << "It's a draw!" << endl;
    break;
  default:
    break;
  }

  cout << "Player X score: " << playerX.getScore() << endl;
  playerX.updateScore(1);
  std::cout << "Player X score: " << playerX.getScore() << std::endl;
  return;
}
} // namespace TicTacToe
