#include "backPropagation.hpp"
#include "database/dataBase.hpp"
#include "gradient.hpp"
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

BackPropagation::BackPropagation(AiModel &_model, double _learning_rate) : model(_model), gradients(_model._model->network.input_size, _model._model->network.output_size, _model._model->network.hidden_layers_size, _model._model->network.hidden_layers_count), learning_rate(_learning_rate) {}

double BackPropagation::get_cross_entropy_loss(vector<double> prediction, vector<double> &target) {
    double loss = 0.0;
    for (size_t i = 0; i < prediction.size(); ++i) {
        if (target[i] == 1.0) {
            loss = -log(prediction[i] + 1e-9);
            break;
        }
    }
    return loss;
}

double BackPropagation::get_total_error(TrainBoard &target, neural_network &temp_network) {

    return get_cross_entropy_loss(
        temp_network.layers[temp_network.hidden_layers_count + 1]
            .getOut(),
        target.prediction_target);
}

vector<double> BackPropagation::calculate_target(Layer &layer, Layer &next_layer, vector<double> &next_delta, vector<double> &target_) {
    vector<double> target(layer.getSize(), 0.0);
    if (layer.getType() == LayerType::OUTPUT) {
        for (int i = 0; i < layer.getSize(); i++) {
            target[i] = layer.getDots()[i].out - target_[i];
        }
    } else if (layer.getType() == LayerType::HIDDEN) {
        for (int i = 0; i < layer.getSize(); i++) {
            target[i] = 0.0;
            for (int j = 0; j < next_layer.getSize(); j++) {
                target[i] += next_delta[j] * next_layer.getWeight(j, i);
            }
        }
    }
    return target;
}

void BackPropagation::clip_gradients(gradient_layer &gradients, double clip_value) {
    for (auto &weights : gradients.weights) {
        for (auto &weight : weights) {
            weight = max(-clip_value, min(weight, clip_value));
        }
    }
}

gradient_layer BackPropagation::calculate_gradient(Layer &layer, vector<double> &deltas) {
    gradient_layer gradient(layer.getSize(), layer.getPrevSize());
    for (int i = 0; i < layer.getSize(); i++) {
        for (int j = 0; j < layer.getPrevSize(); j++) {
            gradient.weights[i][j] = deltas[i] * layer.getDots()[i].out;
        }
    }

    clip_gradients(gradient, CLIP_GRADIENTS);
    return gradient;
}

vector<double> BackPropagation::calculate_derivative(Layer &layer) {
    vector<double> derivatives(layer.getSize(), 1.0);

    if (layer.getType() == LayerType::HIDDEN) {
        for (int i = 0; i < layer.getSize(); i++) {
            if (layer.getDots()[i].out < 0) {
                derivatives[i] = RELU_LEAKY_ALPHA;
            }
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

void BackPropagation::calculate_pattern_gradients(TrainBoard &target_, gradient &gradients, neural_network &temp_network) {
    vector<double> deltas;

    for (int layer_index = gradients.gradients.size() - 1; layer_index > 0; layer_index--) {
        Layer &layer = temp_network.layers[layer_index + 1];
        Layer &next_layer = temp_network.layers[layer_index + ((layer.getType() == LayerType::OUTPUT) ? 0 : 2)];

        vector<double> target = calculate_target(layer, next_layer, deltas, target_.prediction_target);
        vector<double> derivatives = calculate_derivative(layer);

        deltas = calculate_delta(target, derivatives);

        gradients.gradients[layer_index].add(calculate_gradient(layer, deltas));
    }
}

void BackPropagation::check_for_nan(const vector<double> &values) {
    if (isnan(values[0]) || isinf(values[0])) {
        cerr << "NaN/Inf detected in " << values[0] << endl;
        exit(1);
    }
}

double BackPropagation::run_back_propagation(TrainBoard &board, gradient &gradients) {
    neural_network temp_network(model._model->network);

    model._model->run_model(board.board, temp_network);
    calculate_pattern_gradients(board, gradients, temp_network);

    return get_total_error(board, temp_network);
}

double BackPropagation::run_back_propagation(vector<TrainBoard> &boards) {
    gradients.reset();
    double error = 0.0;

    int thread_count = thread::hardware_concurrency();
    vector<thread> threads(thread_count);

    for (int i = 0; i < thread_count; i++) {
        threads[i] = thread([&, i] {
            for (int j = i; j < boards.size(); j += thread_count) {
                error += run_back_propagation(boards[j], gradients);
            }
        });

        threads[i].join();
    }

    int batch_size = boards.size();

    check_for_nan(gradients.gradients[1].weights[0]);
    update_weights(batch_size, gradients);
    error /= batch_size;
    return error;
}

void BackPropagation::update_weights(int batch_size, gradient &gradients) {
    gradients.multiply(-learning_rate / batch_size);
    model._model->updateWeights(gradients);
}
