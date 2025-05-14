#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../src/Board.hpp"
#include "../../src/IPlayer.hpp"

class Player : public IPlayer {
  private:
	int score;
	TicTacToe::cell playerMode;
	TicTacToe::Board *board;

  public:
	Player() {
		board = nullptr;
		score = 0;
		playerMode = TicTacToe::cell::EMPTY;
	}
	virtual ~Player() = default;
	int getScore() override { return score; }
	TicTacToe::cell getBoard(int row, int col) { return board->get(row, col); }
	friend class PlayerAdapter;
	TicTacToe::cell getPlayerMode() override { return playerMode; }
};

#endif // PLAYER_HPP
