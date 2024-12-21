#include "backPropagation.hpp"
#include "database/dataBase.hpp"

BackPropagation::BackPropagation(AiModel &model, double learning_rate) : model(model) {
    this->learning_rate = learning_rate;
}

double BackPropagation::get_error(double prediction, double target) {
    return pow(prediction - target, 2);
}

double BackPropagation::get_total_error(TrainBoard &target) {
    double error = 0.0;
    for (int i = 0; i < target.prediction_target.size(); i++) {
        error += get_error(model._model->getLayer(model._model->getLayerCount() - 1).getDots()[i].out, target.prediction_target[i]);
    }
    return error;
}

// double leakyReluDerivative(double x) { return x > 0 ? 1 : RELU_LEAKY_ALPHA; }

// void BackPropagation::run_back_propagation_layers(TrainBoard &target) {
//     for (int layer_index = this->gradients.size() - 1; layer_index > 0; layer_index--) {
//         vector<vector<double>> temp_gradient(
//             this->gradients[layer_index].size(),
//             vector<double>(this->gradients[layer_index][0].size(), 0.0));
//         vector<double> errors(this->gradients[layer_index].size(), 0.0);
//         for (int dot_index = 0; dot_index < this->gradients[layer_index].size();
//              dot_index++) {
//
//             if (model._model->getLayer(layer_index).getType() == OUTPUT) {
//                 double error = target.prediction_target[dot_index] -
//                                model._model->getLayer(layer_index)
//                                    .getDots()[dot_index]
//                                    .out;
//                 errors[dot_index] = error;
//                 for (int weight_index = 0;
//                      weight_index <
//                      this->gradients[layer_index][dot_index].size();
//                      weight_index++) {
//
//                     temp_gradient[dot_index][weight_index] =
//                         error * model._model->getLayer(layer_index - 1)
//                                     .getDots()[weight_index]
//                                     .out;
//                 }
//             } else if (model._model->getLayer(layer_index).getType() ==
//                        HIDDEN) {
//                 double error = 0.0;
//                 errors[dot_index] = error;
//                 for (int next_dot_index = 0;
//                      next_dot_index < this->gradients[layer_index + 1].size();
//                      next_dot_index++) {
//                     error += errors[next_dot_index] *
//                              model._model->getLayer(layer_index + 1)
//                                  .getWeight(next_dot_index, dot_index);
//                 }
//
//                 for (int weight_index = 0;
//                      weight_index <
//                      this->gradients[layer_index][dot_index].size();
//                      weight_index++) {
//
//                     temp_gradient[dot_index][weight_index] =
//                         error * model._model->getLayer(layer_index - 1)
//                                     .getDots()[weight_index]
//                                     .out;
//                 }
//             }
//
//             for (int weight_index = 0;
//                  weight_index < this->gradients[layer_index][dot_index].size();
//                  weight_index++) {
//                 this->gradients[layer_index][dot_index][weight_index] -=
//                     temp_gradient[dot_index][weight_index];
//             }
//         }
//     }
// }

void BackPropagation::calculate_pattern_gradients(TrainBoard &target, gradient &gradients) {
    gradient pattern_gradient(gradients);

    gradients.add(pattern_gradient);
}

double BackPropagation::run_back_propagation(vector<TrainBoard> &boards) {
    gradient gradients(this->model._model->network);
    double error = 0.0;
    
    for (auto &train_board : boards) {
        model.run_model(train_board.board);
        error += get_total_error(train_board);
        calculate_pattern_gradients(train_board, gradients);
    }

    error /= boards.size();
    return error;
}

void BackPropagation::update_weights(int bash_size, gradient &gradients) {
    gradients.multiply(this->learning_rate / bash_size);
    this->model._model->updateWeights(gradients);
}
