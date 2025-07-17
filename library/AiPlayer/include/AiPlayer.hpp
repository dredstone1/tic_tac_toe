#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include <Globals.hpp>
#include <TicTacToe/Player.hpp>
#include <model.hpp>

class AiPlayer : public tictactoe::Player {
  private:
	nn::model::Model model;
	nn::global::ParamMetrix get_input();
	tictactoe::Cell getBoard_(int index);
	int getCellValue(tictactoe::Cell cellValue, tictactoe::Cell check);

  public:
	AiPlayer(const std::string &config_FileName);
	int getMove() override;
	~AiPlayer() override = default;
	void UserLost() override;
	void UserWin() override;
	void UserDraw() override;
};

#endif // AIPLAYER_HPP
