#include "backPropagation.hpp"
#include "database/dataBase.hpp"
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
            for (int j = 0; j < model._model->getLayer(i).getDots().size();
                 j++) {
                vector<double> newLayer1;
                newLayer1.reserve(
                    model._model->getLayer(i - 1).getDots().size());
                for (int k = 0;
                     k < model._model->getLayer(i - 1).getDots().size(); k++) {
                    newLayer1.emplace_back(0.0);
                }
                newLayer.emplace_back(newLayer1);
            }
        }
        this->gradients.emplace_back(newLayer);
    }
}

double BackPropagation::get_error(TrainBoard &target) {
    double error = 0.0;
    for (int i = 0; i < target.prediction_target.size(); i++) {
        error +=
            pow(target.prediction_target[i] -
                    model._model->getLayer(model._model->getLayerCount() - 1)
                        .getDots()[i]
                        .out,
                2);
    }
    return error;
}

double leakyReluDerivative(double x) { return x > 0 ? 1 : RELU_LEAKY_ALPHA; }

void BackPropagation::run_back_propagation_layers(TrainBoard &target) {
    for (int layer_index = this->gradients.size() - 1; layer_index > 0;
         layer_index--) {

        vector<vector<double>> temp_gradient(
            this->gradients[layer_index].size(),
            vector<double>(this->gradients[layer_index][0].size(), 0.0));

        for (int dot_index = 0; dot_index < this->gradients[layer_index].size();
             dot_index++) {

            double error =
                (model._model->getLayer(layer_index).getType() == OUTPUT)
                    ? target.prediction_target[dot_index]
                    : 0.0;

            if (model._model->getLayer(layer_index).getType() == HIDDEN) {
                for (int new_dot_index_1 = 0;
                     new_dot_index_1 < this->gradients[layer_index + 1].size();
                     new_dot_index_1++) {
                    error += model._model->getLayer(layer_index + 1)
                                 .getDots()[new_dot_index_1]
                                 .out *
                             temp_gradient[new_dot_index_1][dot_index];
                }
            }

            for (int weight_index = 0;
                 weight_index < this->gradients[layer_index][dot_index].size();
                 weight_index++) {
                temp_gradient[dot_index][weight_index] =
                    (this->model._model->getLayer(layer_index)
                         .getDots()[dot_index]
                         .out -
                     error) *
                    ((model._model->getLayer(layer_index).getType() == HIDDEN)
                         ? leakyReluDerivative(
                               model._model->getLayer(layer_index)
                                   .getDots()[dot_index]
                                   .net)
                         : model._model->getLayer(layer_index - 1)
                               .getDots()[weight_index]
                               .out) *
                    model._model->getLayer(layer_index)
                        .getWeight(dot_index, weight_index);
                this->gradients[layer_index][dot_index][weight_index] +=
                    temp_gradient[dot_index][weight_index];
            }
        }
    }
}

void BackPropagation::run_back_propagation(TrainBoard &boards) {
    run_back_propagation_layers(boards);
}

void BackPropagation::run_back_propagation(vector<TrainBoard> &boards) {
    resetGradients();
    double error = 0.0;
    for (auto &train_board : boards) {
        model.run_model(train_board.board);
        error += get_error(train_board);
        run_back_propagation(train_board);
    }
    error /= boards.size();
    cout << error << endl;
    this->update_weights(boards.size());
}

void BackPropagation::update_weights(int bash_size) {
    for (int layer_index = 0; layer_index < this->gradients.size();
         layer_index++) {
        if (this->model._model->getLayer(layer_index).getType() == INPUT) {
            continue;
        }
        for (int dot_index = 0; dot_index < this->gradients[layer_index].size();
             dot_index++) {
            for (int weight_index = 0;
                 weight_index < this->gradients[layer_index][dot_index].size();
                 weight_index++) {
                this->model._model->getLayer(layer_index)
                    .setWeight(dot_index, weight_index,
                               this->model._model->getLayer(layer_index)
                                       .getWeight(dot_index, weight_index) -
                                   this->learning_rate *
                                       this->gradients[layer_index][dot_index]
                                                      [weight_index] /
                                       bash_size);
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
