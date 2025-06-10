#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../src/Board.hpp"
#include "../../src/IPlayer.hpp"

namespace tictactoe {
class Player : public IPlayer {
  private:
	int score;
	Cell playerMode;
	Board *board;

  public:
	Player() {
		board = nullptr;
		score = 0;
		playerMode = Cell::EMPTY;
	}
	virtual ~Player() = default;
	int getScore() override { return score; }
	Cell getBoard(int row, int col) { return board->get(row, col); }
	friend class PlayerAdapter;
	Cell getPlayerMode() override { return playerMode; }
};
} // namespace tictactoe

#endif // PLAYER_HPP
