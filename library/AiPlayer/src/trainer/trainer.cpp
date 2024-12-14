#include "../../include/Trainer/trainer.hpp"
#include "database/dataBase.hpp"
#include <iostream>

int Trainer::train() {
    cout << "Training AI" << endl;

    for (int loop_index = 0; loop_index < this->batch_count; loop_index++) {
        vector<TrainBoard> boards;
        boards.resize(this->batch_size);
        for (int i = 0; i < this->batch_size; i++) {
            boards[i] = this->dataBase.get_next_board();
        }

        this->backPropagation.run_back_propagation(boards);
    }
    return 0;
}

Trainer::Trainer(string file_name, AiModel *_model, int batch_size,
                 int batch_count, double learning_rate)
    : dataBase(file_name), backPropagation(*_model, learning_rate) {
    this->file_name = file_name;
    this->model = _model;
    this->batch_size = batch_size;
    this->batch_count = batch_count;
}
