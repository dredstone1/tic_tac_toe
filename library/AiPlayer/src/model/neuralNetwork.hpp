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
    neural_network(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count, ActivationFunctionType activations);
    ~neural_network() = default;
} neural_network;

#endif // NEURAL_NETWORK
