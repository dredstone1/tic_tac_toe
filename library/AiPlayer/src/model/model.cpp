#include "model.hpp"
#include <cmath>
#include <iostream>
#include <vector>

void model::run_model(const vector<double> &input) {
    run_model(input, network);
}

void print_vector(const vector<double> &metrix) {
    for (auto &value : metrix) {
        cout << value << " ";
    }
    cout << endl
         << endl;
}

void model::run_model(const vector<double> &input, neural_network &temp_network) {
    temp_network.layers[0]->forward(input);
    for (int i = 1; i < temp_network.getLayerCount(); i++) {
        temp_network.layers[i]->forward(temp_network.layers[i - 1]->getOut());
    }
}

void model::reset() {
    for (auto &layer : network.layers) {
        layer->reset();
    }
}

const vector<double> &model::getOutput() const {
    return network.layers[getHiddenLayerCount()]->getOut();
}

void model::updateWeights(const gradient &gradients) {
    for (int i = 0; i < getLayerCount(); i++) {
        getLayer(i).add(gradients.gradients[i]);
    }
}
