#include "backPropagation.hpp"

BackPropagation::BackPropagation(AiModel &model, double learning_rate,
                                 vector<TrainBoard> &train_boards)
    : model(model) {
    this->learning_rate = learning_rate;

    for (TrainBoard &train_board : train_boards) {
        BackPropagationBoard board;
        board.board = train_board;
        board.delta_weights =
            vector<vector<double>>(model._model->getLayerCount() - 1);
    }
}

void BackPropagation::run_back_propagation() {
    
}



