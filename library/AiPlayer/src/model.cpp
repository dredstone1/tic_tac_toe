#include "ActivationFunctions.hpp"
#include "model.hpp"
#include <cmath>
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
    this->layers.at(0).forward(input);
    for (int i = 1; i < this->layers.size(); i++) {
        this->layers.at(i).forward(this->layers.at(i - 1).getDots());
    }
    return 0;
}

void model::reset() {
    for (auto &layer : this->layers) {
        for (auto &dot : layer.getDots()) {
            dot = 0.0;
        }
    }
}
