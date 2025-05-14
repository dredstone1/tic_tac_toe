#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "BoardGrid.hpp"

class IPlayer {
  public:
	virtual int getScore() = 0;
	virtual int getMove() = 0;
	virtual void UserLost() = 0;
	virtual void UserWin() = 0;
	virtual void UserDraw() = 0;
	virtual TicTacToe::cell getPlayerMode() = 0;
	friend class PlayerAdapter;
};

#endif // IPLAYER_HPP
