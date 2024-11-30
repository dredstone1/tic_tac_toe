#include "layer.hpp"
#include <random>

Layer::Layer(int size, int prev_size, LayerType type,
             void (*activations)(vector<double> &metrix)) {
    this->_type = type;
    this->activation = activations;
    this->dots.resize(size);
    this->weights.resize(size, vector<double>(prev_size, 0.0));
    for (auto &neuron_weights : weights) {
        for (auto &weight : neuron_weights) {
            weight = (double)rand() / RAND_MAX;
        }
    }
}

void Layer::forward(vector<double> &metrix) {
    for (int i = 0; i < this->dots.size(); i++) {
        this->dots[i] = 0;
        for (int j = 0; j < weights[j].size(); j++) {
            this->dots[i] += weights[i][j] * metrix[j];
        }
    }
    this->activation(this->dots);
}
