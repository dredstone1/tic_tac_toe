#include "../include/AiPlayer/AiPlayer.hpp"
#include <iostream>

using namespace std;

AiPlayer::AiPlayer() {
    cout << "Creating AI Player" << endl;
    model.basic_setup();
}

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
    std::vector<double> boardState;
    boardState.resize(9);
    for (int i = 0; i < 9; i++) {
        boardState[i] = this->getBoardCellValue(i);
    }
    return boardState;
}

int AiPlayer::getMove() {
    vector<double> input = getBoardVector();
    this->model.run_model(input);
    return this->model.getPrediction(input);
    // return 0;
}

void AiPlayer::UserLost() {}

void AiPlayer::UserWin() {}

void AiPlayer::UserDraw() {}
