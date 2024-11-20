#include <StandartPlayer/StandartPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <iostream>

using namespace TicTacToe;
using namespace std;

int main() {
  StandartPlayer StandardPlayer1;
  StandartPlayer StandardPlayer2;
  cout << "Start Game" << endl;

  Game game(&StandardPlayer1, &StandardPlayer2);

  game.run();
  return 0;
}
