#include "layer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

Layer::Layer(int size, int prev_size, LayerType type,
             ActivationFunctions::ActivationFunctionType activation)
    : activation_function(activation) {
    this->_type = type;
    this->dots.resize(size);
    this->weights.resize(size, vector<double>(prev_size, 0.0));

    for (auto &neuron_weights : weights) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dist(
            0.0, std::sqrt(2.0 / (neuron_weights.size())));
        for (auto &weight : neuron_weights) {
            weight = dist(gen);
        }
    }
}

void Layer::print_activations(const std::vector<double> &activations) {
    double min_val = activations[0], max_val = activations[0], sum = 0.0;
    for (double val : activations) {
        min_val = std::min(min_val, val);
        max_val = std::max(max_val, val);
        sum += val;
    }
    double mean = sum / activations.size();

    double sq_sum = 0.0;
    for (double val : activations) {
        sq_sum += (val - mean) * (val - mean);
    }
    double std_dev = std::sqrt(sq_sum / activations.size());

    std::cout << "Activations: Min=" << min_val << ", Max=" << max_val
              << ", Mean=" << mean << ", StdDev=" << std_dev << std::endl;
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
    print_activations(this->dots);
}
