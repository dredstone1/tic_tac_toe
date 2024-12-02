#ifndef GAME_HPP
#define GAME_HPP

#include "../../src/Board.hpp"
#include "../../src/PlayerAdapter.hpp"

namespace TicTacToe {
class Game {
  public:
    Game(Player *playerX_, Player *playerO_);
    void run();
    PlayerAdapter playerO;
    PlayerAdapter playerX;
    ~Game();

  private:
    Board *board;
};
} // namespace TicTacToe

#endif // GAME_HPP
