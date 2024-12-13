#ifndef ACTIVATIONFUNCTIONS_HPP
#define ACTIVATIONFUNCTIONS_HPP

#include "neuron.hpp"
#include <cmath>
#include <vector>

using namespace std;

namespace ActivationFunctions {
enum ActivationFunctionType {
    SOFTMAX,
    RELU,
    NONE,
};

class ActivationFunction {
  private:
    ActivationFunctionType type;

    static void softmax(vector<neuron> &metrix);
    static void relu(vector<neuron> &metrix);
    static void none(vector<neuron> &metrix);
    static double max_vector(vector<neuron> &metrix);

  public:
    ActivationFunction(ActivationFunctionType type_);
    ~ActivationFunction() = default;
    void activate(vector<neuron> &metrix);
    static void derivitaive_softmax(vector<neuron> &metrix);
    static void derivitaive_relu(vector<neuron> &metrix);
    ActivationFunctionType getType() { return this->type; };
};
}; // namespace ActivationFunctions

#endif // ACTIVATIONFUNCTIONS_HPP
