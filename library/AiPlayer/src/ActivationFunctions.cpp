#include "ActivationFunctions.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

namespace ActivationFunctions {

double ActivationFunction::max_vector(vector<double> &metrix) {
    double max = metrix[0];

    for (auto &value : metrix) {
        if (value > max) {
            max = value;
        }
    }

    return max;
}

ActivationFunction::ActivationFunction(ActivationFunctionType type_) {
    this->type = type_;
}

void ActivationFunction::activate(vector<double> &metrix) {
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

void ActivationFunction::softmax(std::vector<double> &metrix) {
    double max = max_vector(metrix);
    double sum = 0.0;

    for (auto &value : metrix) {
        value = std::exp(value - max);
        sum += value;
    }

    for (auto &value : metrix) {
        value /= sum;
    }
}

void ActivationFunction::relu(vector<double> &metrix) {
    for (auto &layer : metrix) {
        layer = std::max(layer * 0.1, layer);
    }
}

void ActivationFunction::none(vector<double> &metrix) { return; }
}; // namespace ActivationFunctions
