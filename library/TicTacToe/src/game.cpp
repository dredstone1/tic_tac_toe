#include "../include/TicTacToe/game.hpp"
#include "Board.hpp"
#include "BoardGrid.hpp"
#include <iostream>

namespace TicTacToe {

Game::Game(Player *playerX_, Player *playerO_)
    : playerO(cell::EMPTY), playerX(cell::EMPTY) {
	board = new Board();

	playerX.SetPlayer(playerX_, cell::X, board);
	playerO.SetPlayer(playerO_, cell::O, board);
}

Game::~Game() {
	delete board;
}

void Game::run() {
	std::cout << "Start Game loop" << std::endl;
	board->draw();
	PlayerAdapter *currentPlayer = &playerX;

	while (board->GetBoardState() == BoardState::Continue) {
		int move = currentPlayer->getMove();
		if (move < 0 || move > 8 ||
		    board->get(move / 3, move % 3) != cell::EMPTY) {
			std::cout << "Invalid move: << " << move << std::endl;
			continue;
		}

		board->set(move / 3, move % 3, currentPlayer->getPlayerMode());
		board->draw();
		currentPlayer = (currentPlayer == &playerX) ? &playerO : &playerX;
	}

	switch (board->GetBoardState()) {
	case BoardState::WinX:
		playerX.updateScore(playerX.getScore() + 1);
		playerX.UserWin();
		playerO.UserLost();
		break;
	case BoardState::WinO:
		playerO.updateScore(playerO.getScore() + 1);
		playerO.UserWin();
		playerX.UserLost();
		break;
	case BoardState::Draw:
		playerO.UserDraw();
		playerX.UserDraw();
		break;
	default:
		break;
	}
}
} // namespace TicTacToe
