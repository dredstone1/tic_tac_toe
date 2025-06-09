#include "Globals.hpp"
#include <AiModel.hpp>
#include <AiPlayer.hpp>
#include <iostream>
#include <string>
#include <trainer.hpp>

AiPlayer::AiPlayer(const std::string &config_FileName)
    : model(config_FileName, true) {
	load(config_FileName);
}

TicTacToe::cell AiPlayer::getBoard_(int index) {
	return getBoard(index / 3, index % 3);
}

void AiPlayer::load(const std::string &config_FileName) {
	nn::training::Trainer trainer(model);

	trainer.train();
}

int AiPlayer::getCellValue(TicTacToe::cell cellValue, TicTacToe::cell check) {
	return (cellValue == check) ? 1 : 0;
}

nn::global::ParamMetrix AiPlayer::get_input() {
    nn::global::ParamMetrix input(9 * 3, 0);
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i] = getCellValue(getBoard_(i), TicTacToe::cell::X);
	}
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i + 9] = getCellValue(getBoard_(i), TicTacToe::cell::O);
	}
	for (size_t i = 0; i < input.size() / 3; i++) {
		input[i + 9 * 2] = getCellValue(getBoard_(i), TicTacToe::cell::EMPTY);
	}

	return input;
}

int AiPlayer::getMove() {
	model.runModel(get_input());

	nn::Prediction pre = model.getPrediction();
	std::cout << "Ai move: " << pre.index << ", " << pre.value << std::endl;
	return pre.index;
}

void AiPlayer::UserLost() {}

void AiPlayer::UserWin() {}

void AiPlayer::UserDraw() {}
