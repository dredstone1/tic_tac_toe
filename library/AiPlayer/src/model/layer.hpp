#ifndef LAYER_HPP
#define LAYER_HPP

#include "../trainer/gradient.hpp"
#include "ActivationFunctions.hpp"
#include "neuron.hpp"
#include <vector>

using namespace std;

enum LayerType { INPUT,
                 HIDDEN,
                 OUTPUT };

class Layer {
  private:
    LayerType type;
    ActivationFunctions::ActivationFunction activation_function;
    vector<vector<double>> *weights;
    vector<neuron> dots;
    double getRandWeights();
    static void print_activations(const vector<neuron> &activations);

  public:
    Layer(Layer const &other);
    Layer(int _size, int _prev_size, LayerType _type, ActivationFunctions::ActivationFunctionType _activation);
    LayerType getType() { return type; }
    vector<neuron> getDots() { return dots; }
    void forward(vector<neuron> metrix);
    double getWeight(int i, int j) { return (*weights)[i][j]; }
    void setWeight(int i, int j, double weight) { (*weights)[i][j] = weight; }
    ActivationFunctions::ActivationFunctionType getActivation();
    vector<double> getNet();
    vector<double> getOut();
    void updateWeights(gradient_layer const &gradients);
    int getSize() { return dots.size(); }
    int getPrevSize() { return (*weights)[0].size(); }
    ~Layer() = default;
};

#endif // LAYER_HPP
