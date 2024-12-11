#ifndef TRAINER_HPP
#define TRAINER_HPP

#include "../../src/trainer/database/dataBase.hpp"

class Trainer {
  private:
    DataBase dataBase;
  public:
    Trainer();
    int train();
    int load();
    ~Trainer() = default;
};

#endif // TRAINER_HPP
