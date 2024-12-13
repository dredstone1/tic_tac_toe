#include "ActivationFunctions.hpp"
#include "layer.hpp"
#include "model.hpp"
#include "neuron.hpp"
#include <cmath>
#include <iostream>
#include <vector>

model::model(int input_size, int output_size, int hidden_layers_size,
             int hidden_layers_count,
             ActivationFunctions::ActivationFunctionType activations) {
    this->layers.reserve(FIX_LAYER_COUNT + hidden_layers_count);
    this->layers.emplace_back(
        Layer(input_size, 1, LayerType::INPUT,
              ActivationFunctions::ActivationFunctionType::NONE));

    for (int i = 1; i < hidden_layers_count + 1; i++) {
        this->layers.emplace_back(Layer(hidden_layers_size,
                                        this->layers.at(i - 1).getSize(),
                                        LayerType::HIDDEN, activations));
    }

    this->layers.emplace_back(
        Layer(output_size, hidden_layers_size, LayerType::OUTPUT,
              ActivationFunctions::ActivationFunctionType::SOFTMAX));
}

int model::run_model(vector<double> &input) {
    this->reset();
    vector<neuron> input_layer;

    for (auto dot : input) {
        neuron new_neuron;
        new_neuron.out = dot;
        new_neuron.net = dot;
        input_layer.push_back(new_neuron);
    }

    this->layers.at(0).forward(input_layer);
    for (int i = 1; i < this->layers.size(); i++) {
        this->layers.at(i).forward(this->layers.at(i - 1).getDots());
    }
    return 0;
}

void model::BackPropagate(TrainBoard &target, Gradient &gradient) {
    for (int layer_index = this->layers.size() - 1; layer_index >= 0;
         layer_index--) {
        if (this->layers[layer_index].getType() == OUTPUT) {
            vector<neuron> derivative = this->layers[layer_index].getDots();
            ActivationFunctions::ActivationFunction::derivitaive_softmax(
                derivative);

            for (int dot_index = 0;
                 dot_index < this->layers[layer_index].getDots().size() - 1;
                 dot_index++) {
                double delta =
                    (this->layers[layer_index].getDots()[dot_index].out -
                     target.prediction_target[dot_index]) *
                    derivative[dot_index].out;
                for (int last_dot_index = 0;
                     last_dot_index <
                     this->layers[layer_index - 1].getDots().size();
                     last_dot_index++) {
                    gradient[layer_index][dot_index][last_dot_index] +=
                        delta * this->layers[layer_index - 1]
                                    .getDots()[last_dot_index]
                                    .out;
                }
            }
        } else if (this->layers[layer_index].getType() == HIDDEN) {
        }
    }
}

void model::reset() {
    for (auto &layer : this->layers) {
        for (auto &dot : layer.getDots()) {
            dot.out = dot.out = 0.0;
        }
    }
}

vector<double> model::getOutput() {
    vector<double> output;
    for (auto &dot : this->layers[this->layers.size() - 1].getDots()) {
        output.push_back(dot.out);
    }
    return output;
}
