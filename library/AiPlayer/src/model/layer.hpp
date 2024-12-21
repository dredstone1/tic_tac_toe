#ifndef LAYER_HPP
#define LAYER_HPP

#include "ActivationFunctions.hpp"
#include "neuron.hpp"
#include <vector>

using namespace std;

enum LayerType { INPUT, HIDDEN, OUTPUT };

class Layer {
  private:
    LayerType _type;
    ActivationFunctions::ActivationFunction activation_function;
    vector<vector<double>> weights;
    vector<neuron> dots;
    double getRandWeights();
    static void print_activations(const vector<neuron> &activations);

  public:
    Layer(int size, int prev_size, LayerType type,
          ActivationFunctions::ActivationFunctionType activation);
    LayerType getType() { return _type; }
    vector<neuron> getDots() { return dots; }
    void forward(vector<neuron> metrix);
    double getWeight(int i, int j) { return weights[i][j]; }
    void setWeight(int i, int j, double weight) { weights[i][j] = weight; }
    ActivationFunctions::ActivationFunctionType getActivation();
    vector<double> getNet();
    vector<double> getOut();
    void updateWeights(vector<vector<double>> &new_weights);

    ~Layer() = default;
};

#endif // LAYER_HPP
