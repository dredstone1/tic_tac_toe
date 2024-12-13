#include "backPropagation.hpp"
#include <iostream>

BackPropagation::BackPropagation(AiModel &model, double learning_rate)
    : model(model) {
    this->learning_rate = learning_rate;

    this->gradients.reserve(model._model->getLayerCount() + 1);

    for (int i = 0; i < model._model->getLayerCount(); i++) {
        vector<vector<double>> newLayer;
        if (model._model->getLayer(i).getType() == INPUT) {
            newLayer.reserve(0);
        } else {
            newLayer.reserve(model._model->getLayer(i).getDots().size());
            for (int j = 0; j < model._model->getLayer(i).getDots().size() - 1;
                 j++) {
                vector<double> newLayer1;
                newLayer1.reserve(
                    model._model->getLayer(i - 1).getDots().size());
                for (int k = 0;
                     k < model._model->getLayer(i - 1).getDots().size() - 1;
                     k++) {
                    newLayer1.emplace_back(0.0);
                }
                newLayer.emplace_back(newLayer1);
            }
        }
        this->gradients.emplace_back(newLayer);
    }
}

void BackPropagation::run_back_propagation(vector<TrainBoard> &boards) {
    resetGradients();

    for (auto &train_board : boards) {
        model.run_model(train_board.board);

        model._model->BackPropagate(train_board, this->gradients);
    }

    this->update_weights(5);
}

void BackPropagation::update_weights(int bash_size) {
    for (auto &layer : gradients) {
        for (auto &row : layer) {
            for (auto &weight : row) {
                weight += this->learning_rate * weight / bash_size;
            }
        }
    }
}

void BackPropagation::resetGradients() {
    for (auto &layer : this->gradients) {
        for (auto &row : layer) {
            for (auto &weight : row) {
                weight = 0.0;
            }
        }
    }
}
