#include "../../include/Trainer/trainer.hpp"
#include "database/dataBase.hpp"
#include <iostream>

int Trainer::train() {
    std::cout << "Training AI" << std::endl;
    int loop_sum = 5 * this->dataBase.get_train_boards_count() / 5;
    for (int loop_index = 0; loop_index < loop_sum; loop_index++) {
        vector<TrainBoard> boards;
        boards.resize(5);
        for (int i = 0; i < 5; i++) {
            boards[i] = this->dataBase.get_next_board();
        }

        this->backPropagation.run_back_propagation(boards);
    }
    return 0;
}

Trainer::Trainer(string file_name, AiModel *_model)
    : dataBase(file_name), backPropagation(*_model, 0.1) {
    this->file_name = file_name;
    this->model = _model;
}
