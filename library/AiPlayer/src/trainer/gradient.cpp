#include "gradient.hpp"

using namespace std;

void gradient_layer::add(gradient_layer const &new_gradient_layer) {
    for (int j = 0; j < new_gradient_layer.weights.size(); j++) {
        for (int k = 0; k < new_gradient_layer.weights[j].size(); k++) {
            weights[j][k] += new_gradient_layer.weights[j][k];
        }
    }
}

void gradient_layer::reset() {
    for (auto &row : weights) {
        for (auto &weight : row) {
            weight = BASE_GRADIENT_VALUE;
        }
    }
}

gradient_layer::gradient_layer(int size, int prev_size) : weights(size, vector<double>(prev_size, BASE_GRADIENT_VALUE)) {}

gradient_layer::gradient_layer(gradient_layer const &other) {
    weights = other.weights;
    reset();
}

void gradient_layer::multiply(double value) {
    for (auto &cell : weights) {
        for (auto &weight : cell) {
            weight *= value;
        }
    }
}

void gradient::add(gradient const &new_gradient) {
    for (int i = 0; i < gradients.size(); i++) {
        gradients[i].add(new_gradient.gradients[i]);
    }
}

void gradient::reset() {
    for (auto &gradient_layer : gradients) {
        gradient_layer.reset();
    }
}

gradient::gradient(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count) {
    gradients.reserve(hidden_layers_count + 1);
    for (int i = 0; i < hidden_layers_count; i++) {
        if (i == 0) {
            gradients.emplace_back(gradient_layer(hidden_layers_size, input_size));
        } else {
            gradients.emplace_back(gradient_layer(hidden_layers_size, hidden_layers_size));
        }
    }

    gradients.emplace_back(gradient_layer(output_size, hidden_layers_size));
}

void gradient::multiply(double value) {
    for (auto &gradient_layer : gradients) {
        gradient_layer.multiply(value);
    }
}
