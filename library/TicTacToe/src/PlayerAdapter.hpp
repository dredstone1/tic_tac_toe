#ifndef playeradapter_hpp
#define playeradapter_hpp

#include "../include/TicTacToe/Player.hpp"
#include "Board.hpp"
#include "IPlayer.hpp"

class PlayerAdapter : public IPlayer {
  private:
    Player *player;

  public:
    PlayerAdapter(TicTacToe::cell mode);
    void SetPlayer(Player *player_, TicTacToe::cell mode, TicTacToe::Board *board);
    Player *GetPlayer();
    int getScore() override;
    void updateScore(int score);
    int getMove() override;
    TicTacToe::cell getPlayerMode() override;
    void UserLost() override;
    void UserWin() override;
    void UserDraw() override;
};

#endif // PLAYERADAPTER_HPP
