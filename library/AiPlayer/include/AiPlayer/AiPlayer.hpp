#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include <TicTacToe/Player.hpp>

class AiPlayer : public Player {
  public:
    AiPlayer();
    int getMove() override;
    ~AiPlayer() override = default;
    void UserLost() override;
    void UserWin() override;
    void UserDraw() override;
};

#endif // AIPLAYER_HPP
