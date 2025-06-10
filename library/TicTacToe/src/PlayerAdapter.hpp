#ifndef playeradapter_hpp
#define playeradapter_hpp

#include "../include/TicTacToe/Player.hpp"
#include "Board.hpp"
#include "IPlayer.hpp"

namespace tictactoe {
class PlayerAdapter : public IPlayer {
  private:
	Player *player;

  public:
	PlayerAdapter(Cell mode);
	void SetPlayer(Player *player_, Cell mode, Board *board);
	Player *GetPlayer();
	int getScore() override;
	void updateScore(int score);
	int getMove() override;
	Cell getPlayerMode() override;
	void UserLost() override;
	void UserWin() override;
	void UserDraw() override;
};
} // namespace tictactoe

#endif // PLAYERADAPTER_HPP
