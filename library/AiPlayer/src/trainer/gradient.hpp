#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include <vector>
#include "../model/neuralNetwork.hpp"
using namespace std;

#define BASE_GRADIENT_VALUE 0.0

typedef struct gradient {
    vector<vector<vector<double>>> weights;
    void add(gradient const &new_gradient);
    void multiply(double value);
    void reset();
    gradient(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count);
    gradient(gradient const &other);
    gradient(neural_network const &model);
    ~gradient() = default;
} gradient;

#endif // GRADIENT_HPP
