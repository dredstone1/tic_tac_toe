#include <StandardPlayer/StandardPlayer.hpp>
#include <TicTacToe/game.hpp>
#include <iostream>

using namespace TicTacToe;
using namespace std;

int main() {
  StandardPlayer StandardPlayer1;
  StandardPlayer StandardPlayer2;
  cout << "Start Game" << endl;

  Game game(&StandardPlayer1, &StandardPlayer2);

  game.run();
  return 0;
}
