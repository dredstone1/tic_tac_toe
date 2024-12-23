#include "backPropagation.hpp"
#include "database/dataBase.hpp"
#include "gradient.hpp"
#include <vector>

using namespace std;

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

vector<double> BackPropagation::calculate_target(Layer &layer, Layer &next_layer, vector<double> &next_delta, vector<double> &target_) {
    vector<double> target(layer.getSize(), 0.0);
    if (layer.getType() == LayerType::OUTPUT) {
        for (int i = 0; i < layer.getSize(); i++) {
            target[i] = get_error(layer.getDots()[i].out, target_[i]);
        }
    } else if (layer.getType() == LayerType::HIDDEN) {
        for (int i = 1; i < layer.getSize(); i++) {
            double error = 0.0;
            for (int j = 0; j < next_layer.getSize(); j++) {
                error += next_delta[j] * next_layer.getWeight(j, i);
            }
            target[i] = error;
        }
    }
    return target;
}

gradient_layer BackPropagation::calculate_gradient(Layer &layer, vector<double> &deltas) {
    gradient_layer gradient(layer.getSize(), layer.getPrevSize());
    for (int i = 0; i < layer.getSize(); i++) {
        for (int j = 0; j < layer.getPrevSize(); j++) {
            gradient.weights[i][j] = deltas[i] * layer.getDots()[j].out;
        }
    }
    return gradient;
}

vector<double> BackPropagation::calculate_derivative(Layer &layer) {
    vector<double> derivatives(layer.getSize(), 0.0);

    if (layer.getType() == LayerType::OUTPUT) {
        for (int i = 0; i < layer.getSize(); i++) {
            derivatives[i] = layer.getDots()[i].out;
        }
    } else if (layer.getType() == LayerType::HIDDEN) {
        for (int i = 0; i < layer.getSize(); i++) {
            derivatives[i] = (layer.getDots()[i].out > 0) ? 1 : 0.01;
        }
    }

    return derivatives;
}

vector<double> BackPropagation::calculate_delta(vector<double> &target, vector<double> &derivatives) {
    vector<double> new_deltas;
    for (int i = 0; i < target.size(); i++) {
        new_deltas.push_back(target[i] * derivatives[i]);
    }

    return new_deltas;
}

void BackPropagation::calculate_pattern_gradients(TrainBoard &target_, gradient &gradients) {
    vector<double> deltas;

    for (int layer_index = gradients.gradients.size()-1; layer_index > 0; layer_index--) {
        Layer &layer = this->model._model->getLayer(layer_index+1);
        Layer &next_layer = this->model._model->getLayer(layer_index + ((layer.getType() == LayerType::OUTPUT) ? 0 : 2));

        vector<double> target = calculate_target(layer, next_layer, deltas, target_.prediction_target);

        vector<double> derivatives = calculate_derivative(layer);

        deltas = calculate_delta(target, derivatives);

        gradients.gradients[layer_index].add(calculate_gradient(layer, deltas));
    }
}

double BackPropagation::run_back_propagation(vector<TrainBoard> &boards) {
    neural_network &network = this->model._model->network;
    gradient gradients(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count);

    double error = 0.0;

    for (auto &train_board : boards) {
        model.run_model(train_board.board);
        error += get_total_error(train_board);
        calculate_pattern_gradients(train_board, gradients);
    }

    int batch_size = boards.size();
    update_weights(batch_size, gradients);
    error /= batch_size;
    return error;
}

void BackPropagation::update_weights(int batch_size, gradient &gradients) {
    gradients.multiply(-this->learning_rate / batch_size);
    this->model._model->updateWeights(gradients);
}
