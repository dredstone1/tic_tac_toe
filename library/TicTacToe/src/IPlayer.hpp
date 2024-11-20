#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "BoardGrid.hpp"

class IPlayer {
public:
  virtual int getScore() = 0;
  virtual int getMove() = 0;
  virtual TicTacToe::cell getPlayerMode() = 0;
  friend class PlayerAdapter;
};

#endif // IPLAYER_HPP
