#include "ActivationFunctions.hpp"

namespace ActivationFunctions {
void softmax(vector<double> &metrix) {
    double sum = 0;
    for (auto &layer : metrix) {
        layer = exp(layer);
        sum += layer;
    }
    for (auto &layer : metrix) {
        layer /= sum;
    }
}

void relu(vector<double> &metrix) {
    for (auto &layer : metrix) {
        layer = layer > 0 ? layer : 0;
    }
}
} // namespace ActivationFunctions
