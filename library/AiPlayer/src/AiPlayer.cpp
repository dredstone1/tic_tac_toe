#include <AiModel.hpp>
#include <AiPlayer.hpp>
#include <string>
#include <trainer.hpp>
#include <vector>

AiPlayer::AiPlayer(const std::string &config_FileName)
    : model(config_FileName, true) {
	load(config_FileName);
}

void AiPlayer::load(const std::string &config_FileName) {
	nn::Trainer trainer(model);

	trainer.train();
}

std::vector<nn::Global::ValueType> AiPlayer::get_input() {
	std::vector<nn::Global::ValueType> input(9 * 3, 0);

	return input;
}

int AiPlayer::getMove() {
	model.run_model(get_input());

	nn::prediction pre = model.getPrediction();
	return pre.index;
}

void AiPlayer::UserLost() {}

void AiPlayer::UserWin() {}

void AiPlayer::UserDraw() {}
