#include "../../include/Trainer/trainer.hpp"
#include <iostream>

int Trainer::train() {
    std::cout << "Training AI" << std::endl;
    TrainBoard board;
    while ((board = this->dataBase.get_next_board()).board.size() > 0) {
        for (auto num : board.board) {
            std::cout << num << " ";
        }

        for (auto num : board.prediction_target) {
            std::cout << num << " ";
        }
    }
    return 0;
}

Trainer::Trainer(string file_name, AiModel *model) : dataBase(file_name) {
    this->file_name = file_name;
    this->model = model;
}
