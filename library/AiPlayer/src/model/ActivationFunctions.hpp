#ifndef ACTIVATIONFUNCTIONS_HPP
#define ACTIVATIONFUNCTIONS_HPP

#include "neuron.hpp"
#include <cmath>
#include <vector>

#define RELU_LEAKY_ALPHA 0.01

using namespace std;

namespace ActivationFunctions {
enum ActivationFunctionType {
    SOFTMAX,
    RELU_LEAKY,
    NONE,
};

class ActivationFunction {
  private:
    ActivationFunctionType type;

    static void softmax(vector<neuron> &metrix);
    static void relu_leaky(vector<neuron> &metrix);
    static void none(vector<neuron> &metrix);
    static double max_vector(vector<neuron> &metrix);

  public:
    ActivationFunction(ActivationFunctionType type_);
    ~ActivationFunction() = default;
    void activate(vector<neuron> &metrix);
    static void derivitaive_softmax(vector<double> &metrix);
    static void derivitaive_relu_leaky(vector<double> &metrix);
    ActivationFunctionType getType() { return this->type; };
};
}; // namespace ActivationFunctions

#endif // ACTIVATIONFUNCTIONS_HPP
