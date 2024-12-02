#include "ActivationFunctions.hpp"
#include <algorithm>
#include <cmath>
#include <vector>
namespace ActivationFunctions {

void softmax(std::vector<double> &metrix) {
    double max = *std::max_element(metrix.begin(), metrix.end());
    double sum = 0.0;

    for (auto &value : metrix) {
        value = std::exp(value - max);
        sum += value;
    }

    for (auto &value : metrix) {
        value /= sum;
    }
}

void relu(vector<double> &metrix) {
    for (auto &layer : metrix) {
        layer = std::max(0.1 * layer, layer);
    }
}

void none(vector<double> &metrix) { return; }
}; // namespace ActivationFunctions
