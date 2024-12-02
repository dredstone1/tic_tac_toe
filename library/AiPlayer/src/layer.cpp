#include "layer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

Layer::Layer(int size, int prev_size, LayerType type,
             void (*activations)(vector<double> &metrix)) {
    this->_type = type;
    this->activation = activations;
    this->dots.resize(size);
    this->weights.resize(size, vector<double>(prev_size, 0.0));
    for (auto &neuron_weights : weights) {
        for (auto &weight : neuron_weights) {
            weight = this->getRandWeights();
            std::cout << weight << endl;
        }
    }
}

double Layer::getRandWeights() {
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(-1000, 1000);

    return distribution(generator) / 1000.0;
}

void Layer::forward(vector<double> metrix) {
    if (this->_type == LayerType::INPUT) {
        for (int i = 0; i < this->dots.size(); i++) {
            this->dots[i] = metrix[i];
        }
    } else {
        for (int i = 0; i < this->dots.size(); i++) {
            this->dots[i] = 0.0;
            for (int j = 0; j < this->weights[j].size(); j++) {
                this->dots[i] += this->weights[i][j] * metrix[j];
            }
        }
    }
    this->activation(this->dots);

    std::cout << "Layer: " << this->_type << std::endl;
    for (auto &dot : this->dots) {
        if (dot > 1 || dot < 0) {
            std::cout << "\033[31m";
            std::cout << "Out of range: ";
        }
        std::cout << dot << " ";
        std::cout << "\033[0m";
    }
    std::cout << std::endl;
}
