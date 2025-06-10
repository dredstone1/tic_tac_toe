#include "../include/TicTacToe/game.hpp"
#include "Board.hpp"
#include "BoardGrid.hpp"
#include <iostream>

namespace tictactoe {

Game::Game(Player *playerX_, Player *playerO_)
    : playerO(Cell::EMPTY), playerX(Cell::EMPTY) {
	board = new Board();

	playerX.SetPlayer(playerX_, Cell::X, board);
	playerO.SetPlayer(playerO_, Cell::O, board);
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
		    board->get(move / 3, move % 3) != Cell::EMPTY) {
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
} // namespace tictactoe
