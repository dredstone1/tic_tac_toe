#ifndef IPLAYER_HPP
#define IPLAYER_HPP

#include "BoardGrid.hpp"

namespace tictactoe {
class IPlayer {
  public:
	virtual int getScore() = 0;
	virtual int getMove() = 0;
	virtual void UserLost() = 0;
	virtual void UserWin() = 0;
	virtual void UserDraw() = 0;
	virtual Cell getPlayerMode() = 0;
	friend class PlayerAdapter;
};
} // namespace tictactoe

#endif // IPLAYER_HPP
