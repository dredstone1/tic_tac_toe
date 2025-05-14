#ifndef STANDARDPLAYER_HPP
#define STANDARDPLAYER_HPP
#include <TicTacToe/Player.hpp>

class StandardPlayer : public Player {
  public:
	StandardPlayer();
	int getMove() override;
	~StandardPlayer() override = default;
	void UserLost() override;
	void UserWin() override;
	void UserDraw() override;
};

#endif // STANDARDPLAYER_HPP
