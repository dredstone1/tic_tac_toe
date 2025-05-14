#include "../include/AiPlayer/AiPlayer.hpp"

using namespace std;

AiPlayer::AiPlayer() { ai_model = new AiModel(); }

AiPlayer::AiPlayer(AiModel *_ai_model) { ai_model = _ai_model; }

double AiPlayer::getBoardCellValue(int dot) {
	switch (getBoard(dot / 3, dot % 3)) {
	case TicTacToe::cell::X:
		return CELL_VALUE_X;
	case TicTacToe::cell::O:
		return CELL_VALUE_O;
	case TicTacToe::cell::EMPTY:
		return CELL_VALUE_EMPTY;
	};
	return 0;
}

vector<double> AiPlayer::getBoardVector() {
	vector<double> boardState(9);

	for (int i = 0; i < 9; i++) {
		boardState[i] = getBoardCellValue(i);
	}
	return boardState;
}

int AiPlayer::getMove() {
	vector<double> input = getBoardVector();
	ai_model->run_model(input);
	return ai_model->getPrediction(input);
}

void AiPlayer::UserLost() {}

void AiPlayer::UserWin() {}

void AiPlayer::UserDraw() {}
