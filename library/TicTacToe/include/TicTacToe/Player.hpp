#include "../../src/BoardGrid.hpp"

namespace player {
class Player {
public:
  virtual void getMove(TicTacToe::BoardGrid grid);
  virtual ~Player() {}
};
} // namespace player
