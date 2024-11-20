#include "../include/StandartPlayer/StandartPlayer.hpp"
#include <iostream>

using namespace std;

StandartPlayer::StandartPlayer() { }

int StandartPlayer::getMove() {
  cout << getPlayerMode() << ": Enter your move: ";
  int move;
  cin >> move;
  return move;
}
