#ifndef TRAINER_HPP
#define TRAINER_HPP

#include "../../src/trainer/database/dataBase.hpp"
#include "../AiPlayer/AiModel.hpp"

class Trainer {
  private:
    string file_name;
    DataBase dataBase;
    AiModel *model;

  public:
    Trainer(string file_name, AiModel *model);
    int train();
    int load();
    ~Trainer() = default;
};

#endif // TRAINER_HPP
