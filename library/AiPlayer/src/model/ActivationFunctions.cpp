#include "ActivationFunctions.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

namespace ActivationFunctions {

double ActivationFunction::max_vector(vector<neuron> &metrix) {
    double max = metrix[0].net;

    for (auto &value : metrix) {
        if (value.net > max) {
            max = value.net;
        }
    }

    return max;
}

ActivationFunction::ActivationFunction(ActivationFunctionType type_) {
    this->type = type_;
}

void ActivationFunction::activate(vector<neuron> &metrix) {
    switch (this->type) {
    case ActivationFunctionType::SOFTMAX:
        softmax(metrix);
        break;
    case ActivationFunctionType::RELU:
        relu(metrix);
        break;
    case ActivationFunctionType::NONE:
        none(metrix);
        break;
    }
}

void ActivationFunction::softmax(std::vector<neuron> &metrix) {
    double max = max_vector(metrix);
    double sum = 0.0;

    for (auto &value : metrix) {
        value.out = std::exp(value.net - max);
        sum += value.out;
    }

    for (auto &value : metrix) {
        value.out /= sum;
    }
}

void ActivationFunction::relu(vector<neuron> &metrix) {
    for (auto &layer : metrix) {
        layer.out = std::max(0.1 * layer.net, layer.net);
    }
}

void ActivationFunction::derivitaive_softmax(vector<neuron> &metrix) {
    // 1. Calculate the Softmax of the input vector
    std::vector<double> softmax_output(metrix.size());
    double sum_exp = 0.0;

    for (size_t i = 0; i < metrix.size(); ++i) {
        softmax_output[i] = std::exp(metrix[i].net);
        sum_exp += softmax_output[i];
    }

    for (size_t i = 0; i < metrix.size(); ++i) {
        softmax_output[i] /= sum_exp;
    }

    for (size_t i = 0; i < metrix.size(); ++i) {
        for (size_t j = 0; j < metrix.size(); ++j) {
            metrix[i].net = (i == j)
                                ? softmax_output[i] * (1 - softmax_output[i])
                                : -softmax_output[i] * softmax_output[j];
        }
    }
}

void ActivationFunction::derivitaive_relu(vector<neuron> &metrix) {
    for (size_t i = 0; i < metrix.size(); ++i) {
        metrix[i].net = (metrix[i].net > 0) ? 1.0 : 0.1;
    }
}

void ActivationFunction::none(vector<neuron> &metrix) { return; }
}; // namespace ActivationFunctions
