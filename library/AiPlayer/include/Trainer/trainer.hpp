#ifndef TRAINER_HPP
#define TRAINER_HPP

#include "../../src/trainer/backPropagation.hpp"
#include "../../src/trainer/database/dataBase.hpp"
#include "../AiPlayer/AiModel.hpp"

#define graph_resolution 1000

class Trainer {
  private:
    string file_name;
    DataBase dataBase;
    AiModel *model;
    BackPropagation backPropagation;
    int batch_size;
    int batch_count;
    static void print_progress_bar(int current, int total);

  public:
    Trainer(string file_name, AiModel *model, int batch_size, int batch_count,
            double learning_rate);
    int train();
    ~Trainer() = default;
};

#endif // TRAINER_HPP
