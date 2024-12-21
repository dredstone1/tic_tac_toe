#include "gradient.hpp"

void gradient::add(gradient const &new_gradient) {
    for (int i = 0; i < new_gradient.weights.size(); i++) {
        for (int j = 0; j < new_gradient.weights[i].size(); j++) {
            for (int k = 0; k < new_gradient.weights[i][j].size(); k++) {
                this->weights[i][j][k] += new_gradient.weights[i][j][k];
            }
        }
    }
}

void gradient::reset() {
    for (auto &layer : this->weights) {
        for (auto &row : layer) {
            for (auto &weight : row) {
                weight = BASE_GRADIENT_VALUE;
            }
        }
    }
}

gradient::gradient(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count) {
    this->weights.resize(hidden_layers_count + 1);
    this->weights[hidden_layers_count].resize(output_size);

    for (int i = 0; i < hidden_layers_count; i++) {
        this->weights[i].resize(hidden_layers_size);
    }

    for (int i = 0; i < hidden_layers_count + 1; i++) {
        for (int j = 0; j < this->weights[i].size(); j++) {
            if (i == 0) {
                this->weights[i][j].resize(input_size);
            } else {
                this->weights[i][j].resize(this->weights[i - 1].size());
            }
        }
    }
}

gradient::gradient(gradient const &other) {
    this->weights = other.weights;
    this->reset();
}

gradient::gradient(neural_network const &model) : gradient(model.input_size, model.output_size, model.hidden_layers_size, model.hidden_layers_count) {}

void gradient::multiply(double value) {
    for (auto &layer : this->weights) {
        for (auto &cell : layer) {
            for (auto &weight : cell) {
                weight *= value;
            }
        }
    }
}
