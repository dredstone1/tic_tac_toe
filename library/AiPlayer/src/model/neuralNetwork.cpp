#include "ActivationFunctions.hpp"
#include "neuralNetwork.hpp"

neural_network::neural_network(int _input_size, int _output_size, int _hidden_layers_size, int _hidden_layers_count, ActivationFunctionType _activations) {
    input_size = _input_size;
    output_size = _output_size;
    hidden_layers_size = _hidden_layers_size;
    hidden_layers_count = _hidden_layers_count;

    layers.reserve(FIX_LAYER_COUNT + _hidden_layers_count);
    layers.emplace_back(
        Layer(input_size, 1, LayerType::INPUT,
              ActivationFunctionType::NONE));

    for (int i = 1; i < hidden_layers_count + 1; i++) {
        layers.emplace_back(Layer(hidden_layers_size,
                                        layers.at(i - 1).getDots().size(),
                                        LayerType::HIDDEN, _activations));
    }

    layers.emplace_back(
        Layer(output_size, hidden_layers_size, LayerType::OUTPUT,
              ActivationFunctionType::SOFTMAX));
}

neural_network::neural_network(neural_network const &other) {
    input_size = other.input_size;
    output_size = other.output_size;
    hidden_layers_size = other.hidden_layers_size;
    hidden_layers_count = other.hidden_layers_count;
    for (auto &layer : other.layers) {
        Layer layer_(layer);
        layers.emplace_back(layer_);
    }
}
