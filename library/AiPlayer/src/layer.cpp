#include "layer.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>

Layer::Layer(int size, int prev_size, LayerType type,
             ActivationFunctions::ActivationFunctionType activation)
    : activation_function(activation) {
    this->_type = type;
    this->dots.resize(size);
    this->weights.resize(size, vector<double>(prev_size, 0.0));
    for (auto &neuron_weights : weights) {
        for (auto &weight : neuron_weights) {
            weight = this->getRandWeights();
        }
    }
}

double Layer::getRandWeights() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(-1000, 1000);

    return distribution(generator) / 100.0;
}

void Layer::forward(vector<double> metrix) {
    if (this->_type == LayerType::INPUT) {
        this->dots = metrix;
    } else {
        for (size_t i = 0; i < this->dots.size(); ++i) {
            this->dots[i] = 0.0;
            for (size_t j = 0; j < metrix.size(); ++j) {
                this->dots[i] += this->weights[i][j] * metrix[j];
            }
        }
    }

    this->activation_function.activate(this->dots);

    std::cout << "Layer: " << this->_type << std::endl;
    for (auto &dot : this->dots) {
        cout << fixed << setprecision(numeric_limits<double>::max_digits10)
             << dot << " ";
    }
    std::cout << std::endl;
}
