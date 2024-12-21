#include "neuralNetwork.hpp"
#include "ActivationFunctions.hpp"

neural_network::neural_network(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count, ActivationFunctionType activations) {
    this->input_size = input_size;
    this->output_size = output_size;
    this->hidden_layers_size = hidden_layers_size;
    this->hidden_layers_count = hidden_layers_count;

    this->layers.reserve(FIX_LAYER_COUNT + hidden_layers_count);
    this->layers.emplace_back(
        Layer(input_size, 1, LayerType::INPUT,
              ActivationFunctionType::NONE));

    for (int i = 1; i < hidden_layers_count + 1; i++) {
        this->layers.emplace_back(Layer(hidden_layers_size,
                                        this->layers.at(i - 1).getDots().size(),
                                        LayerType::HIDDEN, activations));
    }

    this->layers.emplace_back(
        Layer(output_size, hidden_layers_size, LayerType::OUTPUT,
              ActivationFunctionType::SOFTMAX));
}
