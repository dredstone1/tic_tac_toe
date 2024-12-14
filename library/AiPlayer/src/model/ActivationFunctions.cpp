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
    case ActivationFunctionType::RELU_LEAKY:
        relu_leaky(metrix);
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

void ActivationFunction::relu_leaky(vector<neuron> &metrix) {
    for (auto &layer : metrix) {
        layer.out = std::max(RELU_LEAKY_ALPHA * layer.net, layer.net);
    }
}

void ActivationFunction::derivitaive_softmax(vector<double> &metrix) {
    int size = metrix.size();

    std::vector<double> activations(size);
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        activations[i] = std::exp(metrix[i]);
        sum += activations[i];
    }
    for (int i = 0; i < size; ++i) {
        metrix[i] = activations[i] / sum;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                metrix[i] = metrix[i] * (1 - metrix[i]);
            } else {
                metrix[i] = -metrix[i] * metrix[j];
            }
        }
    }
}

void ActivationFunction::derivitaive_relu_leaky(vector<double> &metrix) {
    for (size_t i = 0; i < metrix.size(); ++i) {
        metrix[i] = (metrix[i] > 0) ? 1.0 : RELU_LEAKY_ALPHA;
    }
}

void ActivationFunction::none(vector<neuron> &metrix) { return; }
}; // namespace ActivationFunctions
