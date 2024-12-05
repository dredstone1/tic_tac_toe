#include "ActivationFunctions.hpp"
#include "model.hpp"
#include <cmath>
#include <iostream>
#include <vector>

model::model(int input_size, int output_size, int hidden_layers_size,
             int hidden_layers_count) {
    this->layers.reserve(FIX_LAYER_COUNT + hidden_layers_count);
    this->layers.emplace_back(
        Layer(input_size, 1, LayerType::INPUT, ActivationFunctions::none));
    for (int i = 1; i < hidden_layers_count + 1; i++) {
        this->layers.emplace_back(
            Layer(hidden_layers_size, this->layers[i - 1].getSize(),
                  LayerType::HIDDEN, ActivationFunctions::relu));
    }

    this->layers.emplace_back(Layer(output_size, hidden_layers_size,
                                    LayerType::OUTPUT,
                                    ActivationFunctions::softmax));
}

int model::run_model(vector<double> &input) {
    this->layers[0].forward(input);
    std::cout << "Running model, length: " << this->layers.size() << std::endl;
    for (int i = 1; i < this->layers.size(); i++) {
        this->layers[i].forward(this->layers[i - 1].getDots());
    }
    return 0;
}
