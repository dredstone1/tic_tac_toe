#include "../../src/Board.hpp"
#include "Player.hpp"

#ifndef GAME_HPP
#define GAME_HPP

namespace TicTacToe {
class Game {
public:
  Game();
  void run();
  // player::Player PLAYERX;
  // player::Player PLAYERO;
  //
private:
  Board board;
};
} // namespace TicTacToe

#endif // GAME_HPP
