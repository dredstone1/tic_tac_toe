#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include "ActivationFunctions.hpp"
#include "layer.hpp"

#define FIX_LAYER_COUNT 2

using namespace ActivationFunctions;

typedef struct neural_network {
    vector<Layer> layers;
    int input_size;
    int output_size;
    int hidden_layers_size;
    int hidden_layers_count;
    neural_network(int _input_size, int _output_size, int _hidden_layers_size, int _hidden_layers_count, ActivationFunctionType _activations);
    neural_network(neural_network const &other);
    ~neural_network() = default;
} neural_network;

#endif // NEURAL_NETWORK
