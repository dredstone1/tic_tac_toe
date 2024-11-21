#include "../include/StandardPlayer/StandardPlayer.hpp"
#include <iostream>

using namespace std;

StandardPlayer::StandardPlayer() { }

int StandardPlayer::getMove() {
  cout << (char)getPlayerMode() << ": Enter your move: ";
  int move;
  cin >> move;
  return move;
}
