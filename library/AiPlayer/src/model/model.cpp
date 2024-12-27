#include "model.hpp"
#include "neuron.hpp"
#include <cmath>
#include <vector>

int model::run_model(vector<double> &input) {
    reset();
    return run_model(input, network);
}

int model::run_model(vector<double> &input, neural_network &temp_network) {
    vector<neuron> input_layer;
    for (auto dot : input) {
        neuron new_neuron;
        new_neuron.out = dot;
        new_neuron.net = dot;
        input_layer.push_back(new_neuron);
    }
        
    temp_network.layers[0].forward(input_layer);
    for (int i = 1; i < temp_network.layers.size(); i++) {
        temp_network.layers[i].forward(temp_network.layers[i - 1].getDots());
    }
    return 0;
}

void model::reset() {
    for (auto &layer : network.layers) {
        for (auto &dot : layer.getDots()) {
            dot.out = dot.net = 0.0;
        }
    }
}

vector<double> model::getOutput() {
    return getLayer(getLayerCount() - 1).getOut();
}

void model::updateWeights(gradient &gradients) {
    for (int i = 1; i < getLayerCount(); i++) {
        getLayer(i).updateWeights(gradients.gradients[i-1]);
    }
}
