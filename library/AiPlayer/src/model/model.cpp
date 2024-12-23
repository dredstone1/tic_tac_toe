#include "model.hpp"
#include "neuron.hpp"
#include <cmath>
#include <vector>

int model::run_model(vector<double> &input) {
    this->reset();
    vector<neuron> input_layer;

    for (auto dot : input) {
        neuron new_neuron;
        new_neuron.out = dot;
        new_neuron.net = dot;
        input_layer.push_back(new_neuron);
    }

    this->getLayer(0).forward(input_layer);
    for (int i = 1; i < this->getLayerCount(); i++) {
        this->getLayer(i).forward(this->getLayer(i - 1).getDots());
    }
    return 0;
}

void model::reset() {
    for (auto &layer : this->network.layers) {
        for (auto &dot : layer.getDots()) {
            dot.out = dot.net = 0.0;
        }
    }
}

vector<double> model::getOutput() {
    return this->getLayer(this->getLayerCount() - 1).getOut();
}

void model::updateWeights(gradient &gradients) {
    for (int i = 1; i < this->getLayerCount(); i++) {
        this->getLayer(i).updateWeights(gradients.gradients[i-1]);
    }
}
