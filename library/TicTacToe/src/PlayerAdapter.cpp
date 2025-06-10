#include "PlayerAdapter.hpp"

namespace tictactoe {
PlayerAdapter::PlayerAdapter(Cell mode) { player = 0; }

void PlayerAdapter::updateScore(int score) {
	if (score > 0) {
		(*player).score = score;
	}
}

int PlayerAdapter::getMove() { return player->getMove(); }

int PlayerAdapter::getScore() { return player->getScore(); }

void PlayerAdapter::SetPlayer(Player *player_, Cell mode, Board *board) {
	player = player_;
	player->playerMode = mode;
	player->score = 0;
	player->board = board;
}

Player *PlayerAdapter::GetPlayer() { return player; }

Cell PlayerAdapter::getPlayerMode() {
	return player->getPlayerMode();
}

void PlayerAdapter::UserLost() { player->UserLost(); }
void PlayerAdapter::UserWin() { player->UserWin(); }
void PlayerAdapter::UserDraw() { player->UserDraw(); }
} // namespace tictactoe
