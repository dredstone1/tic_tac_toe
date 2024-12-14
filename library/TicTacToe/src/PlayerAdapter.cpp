#include "PlayerAdapter.hpp"

PlayerAdapter::PlayerAdapter(TicTacToe::cell mode) { player = 0; }

void PlayerAdapter::updateScore(int score) {
    if (score > 0) {
        (*this->player).score = score;
    }
}

int PlayerAdapter::getMove() { return player->getMove(); }

int PlayerAdapter::getScore() { return player->getScore(); }

void PlayerAdapter::SetPlayer(Player *player_, TicTacToe::cell mode,
                              TicTacToe::Board *board) {
    this->player = player_;
    this->player->playerMode = mode;
    this->player->score = 0;
    this->player->board = board;
}

Player *PlayerAdapter::GetPlayer() { return player; }

TicTacToe::cell PlayerAdapter::getPlayerMode() {
    return player->getPlayerMode();
}

void PlayerAdapter::UserLost() { player->UserLost(); }
void PlayerAdapter::UserWin() { player->UserWin(); }
void PlayerAdapter::UserDraw() { player->UserDraw(); }
