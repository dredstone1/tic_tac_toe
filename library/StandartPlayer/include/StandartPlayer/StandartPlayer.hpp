#ifndef STANDARTPLAYER_HPP
#define STANDARTPLAYER_HPP
#include <TicTacToe/Player.hpp>

class StandartPlayer : public Player {
public:
  StandartPlayer();
  int getMove() override;
  ~StandartPlayer() override = default;
};
#endif // STANDARTPLAYER_HPP
