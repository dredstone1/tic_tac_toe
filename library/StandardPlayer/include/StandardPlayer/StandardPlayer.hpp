#ifndef STANDARTPLAYER_HPP
#define STANDARTPLAYER_HPP
#include <TicTacToe/Player.hpp>

class StandardPlayer : public Player {
public:
  StandardPlayer();
  int getMove() override;
  ~StandardPlayer() override = default;
};
#endif // STANDARTPLAYER_HPP
