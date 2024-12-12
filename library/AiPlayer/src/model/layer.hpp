#ifndef LAYER_HPP
#define LAYER_HPP

#include "ActivationFunctions.hpp"
#include <vector>
using namespace std;
enum LayerType { INPUT, HIDDEN, OUTPUT };

class Layer {
  private:
    LayerType _type;
    ActivationFunctions::ActivationFunction activation_function;
    vector<vector<double>> weights;
    vector<double> dots;
    double getRandWeights();
    static void print_activations(const std::vector<double> &activations);

  public:
    Layer(int size, int prev_size, LayerType type,
          ActivationFunctions::ActivationFunctionType activation);
    LayerType getType() { return _type; }
    int getSize() { return dots.size(); }
    vector<double> getDots() { return dots; }
    void forward(vector<double> metrix);
    ~Layer() = default;
    double getWeight(int i, int j) { return weights[i][j]; }
    void setWeight(int i, int j, double weight) { weights[i][j] = weight; }
    ActivationFunctions::ActivationFunctionType getActivation() {
        return activation_function.getType();
    }
};

#endif // LAYER_HPP
