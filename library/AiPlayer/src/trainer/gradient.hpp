#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include <vector>
using namespace std;

#define BASE_GRADIENT_VALUE 0.0

typedef struct gradient_layer {
    vector<vector<double>> weights;
    void add(gradient_layer const &new_gradient);
    void multiply(double value);
    void reset();
    gradient_layer(int size, int prev_size);
    gradient_layer(gradient_layer const &other);
    ~gradient_layer() = default;
} gradient_layer;

typedef struct gradient {
    vector<gradient_layer> gradients;
    void add(gradient const &new_gradient);
    void multiply(double value);
    void reset();
    ~gradient() = default;
    gradient(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count);
} gradient;

#endif // GRADIENT_HPP
