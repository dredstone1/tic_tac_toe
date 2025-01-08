#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include "AiModel.hpp"
#include <TicTacToe/Player.hpp>

#define CELL_VALUE_X 1.0
#define CELL_VALUE_O 0.0
#define CELL_VALUE_EMPTY 0.5

class AiPlayer : public Player {
  private:
    AiModel *ai_model;
    double getBoardCellValue(int dot);

  public:
    AiPlayer();
    AiPlayer(AiModel *_ai_model);
    int getMove() override;
    ~AiPlayer() override = default;
    void UserLost() override;
    void UserWin() override;
    void UserDraw() override;
    vector<double> getBoardVector();
};

#endif // AIPLAYER_HPP
