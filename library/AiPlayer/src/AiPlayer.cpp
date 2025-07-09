#include "Globals.hpp"
#include <AiModel.hpp>
#include <AiPlayer.hpp>
#include <iostream>
#include <string>

AiPlayer::AiPlayer(const std::string &config_FileName)
    : model(config_FileName) {
	model.train();
}

tictactoe::Cell AiPlayer::getBoard_(int index) {
	return getBoard(index / 3, index % 3);
}

int AiPlayer::getCellValue(tictactoe::Cell cellValue, tictactoe::Cell check) {
	return (cellValue == check) ? 1 : 0;
}

nn::global::ParamMetrix AiPlayer::get_input() {
	nn::global::ParamMetrix input(9 * 3, 0);
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i] = getCellValue(getBoard_(i), tictactoe::Cell::X);
	}
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i + 9] = getCellValue(getBoard_(i), tictactoe::Cell::O);
	}
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i + 9 * 2] = getCellValue(getBoard_(i), tictactoe::Cell::EMPTY);
	}

	return input;
}

int AiPlayer::getMove() {
	model.runModel(get_input());

	nn::global::FinalPrediction pre = model.getPrediction();
	std::cout << "Ai move: " << pre.index << ", " << pre.value << std::endl;
	return pre.index;
}

void AiPlayer::UserLost() {}

void AiPlayer::UserWin() {}

void AiPlayer::UserDraw() {}
