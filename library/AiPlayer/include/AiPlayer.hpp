#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include <AiModel.hpp>
#include <Globals.hpp>
#include <TicTacToe/Player.hpp>

class AiPlayer : public Player {
  private:
	nn::AiModel model;
	void load(const std::string &config_FileName);
	nn::global::ParamMetrix get_input();
    TicTacToe::cell getBoard_(int index);
    int getCellValue(TicTacToe::cell cellValue, TicTacToe::cell check);

  public:
	AiPlayer(const std::string &config_FileName);
	int getMove() override;
	~AiPlayer() override = default;
	void UserLost() override;
	void UserWin() override;
	void UserDraw() override;
};

#endif // AIPLAYER_HPP
