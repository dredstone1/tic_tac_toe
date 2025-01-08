#include "LayerParameters.hpp"
#include <cmath>
#include <random>
#include <vector>

// LayerParameters::LayerParameters(const int size, const int prev_size, const bool random) {
//     weights.resize(size, vector<double>(prev_size, 0.0));
//     bias.resize(size, BIAS_INIT);
//
//     if (!random)
//         return;
//
//
//     for (int i = 0; i < size; i++) {
//
//
//         for (int j = 0; j < prev_size; j++) {
//             weights = 
//         }
//     }
// }

LayerParameters::LayerParameters(const int size, const int prev_size, const bool random) {
    weights.resize(size, vector<double>(prev_size, 0.0));
    bias.resize(size, BIAS_INIT);

    if (!random)
        return;

    // Initialize weights using a random distribution
    std::random_device rd;
    std::mt19937 gen(rd());

    // Choose an appropriate initialization method:
    // 1. Xavier/Glorot Initialization (Normal Distribution):
    //    - Good for layers with activation functions like tanh or sigmoid.
    //    - Scales the variance of the weights based on the number of input and output connections.

    //    std::normal_distribution<> dist(0.0, sqrt(2.0 / (prev_size + size))); 

    // 2. He Initialization (Normal Distribution):
    //    - Good for layers with ReLU or Leaky ReLU activations.
    //    - Scales the variance of the weights based primarily on the number of input connections.

    std::normal_distribution<> dist(0.0, sqrt(2.0 / prev_size));

    // 3. Uniform Distribution (within a specific range):
    //    - Can also be used, but normal distributions are generally preferred.
    // double range = sqrt(6.0 / (prev_size + size)); // Example range for Xavier uniform
    // std::uniform_real_distribution<> dist(-range, range); 

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < prev_size; j++) {
            weights[i][j] = dist(gen); // Assign the random weight
        }
    }
}

void LayerParameters::reset() {
    for (int i = 0; i < getSize(); i++) {
        bias[i] = 0.0;

        for (int j = 0; j < getPrevSize(); j++) {
            weights[i][j] = 0.0;
        }
    }
}

void LayerParameters::add(const LayerParameters &new_gradient_layer) {
    for (int i = 0; i < getSize(); i++) {
        bias[i] += new_gradient_layer.bias[i];

        for (int j = 0; j < getPrevSize(); j++) {
            weights[i][j] += new_gradient_layer.weights[i][j];
        }
    }
}

void LayerParameters::multiply(const double value) {
    for (int i = 0; i < getSize(); i++) {
        bias[i] *= value;

        for (int j = 0; j < getPrevSize(); j++) {
            weights[i][j] *= value;
        }
    }
}

LayerParameters::LayerParameters(LayerParameters const &other) : weights(other.weights), bias(other.bias) {}
