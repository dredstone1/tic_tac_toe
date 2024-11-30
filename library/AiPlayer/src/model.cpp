#include "ActivationFunctions.hpp"
#include "model.hpp"
#include <cmath>
#include <vector>

model::model(int input_size, int output_size, int hidden_layers_size,
             int hidden_layers_count) {
    this->layers.reserve(FIX_LAYER_COUNT + hidden_layers_count);
    this->layers[0] =
        Layer(input_size, 1, LayerType::INPUT, ActivationFunctions::none);
    for (int i = 1; i < hidden_layers_count + 1; i++) {
        this->layers[i] =
            Layer(hidden_layers_size, this->layers[i - 1].getSize(),
                  LayerType::HIDDEN, ActivationFunctions::relu);
    }

    this->layers[hidden_layers_count + 1] =
        Layer(output_size, hidden_layers_size, LayerType::OUTPUT,
              ActivationFunctions::softmax);
}
