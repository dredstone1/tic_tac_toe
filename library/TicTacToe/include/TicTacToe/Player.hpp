#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../src/IPlayer.hpp"

class Player : public IPlayer {
private:
  int score;
  TicTacToe::cell playerMode;

public:
  Player() {
    score = 0;
    playerMode = TicTacToe::cell::EMPTY;
  }
  virtual ~Player() = default;
  int getScore() override { return score; }
  friend class PlayerAdapter;
  TicTacToe::cell getPlayerMode() override { return playerMode; }
};

#endif // IPLAYER_HPP
