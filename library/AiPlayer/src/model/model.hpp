#ifndef MODEL_HPP
#define MODEL_HPP

#include "../trainer/gradient.hpp"
#include "layer.hpp"
#include "neuralNetwork.hpp"

class model {
  private:
      neural_network network;
      friend class BackPropagation;
  public:
    model(int input_size, int output_size, int hidden_layers_size, int hidden_layers_count, ActivationFunctions::ActivationFunctionType activations) : network(input_size, output_size, hidden_layers_size, hidden_layers_count, activations) {}
    ~model() = default;
    int run_model(vector<double> &input);
    vector<double> getOutput();
    void reset();
    int getLayerCount() { return (this->network.hidden_layers_count + FIX_LAYER_COUNT); }
    Layer &getLayer(int i) { return this->network.layers.at(i); }
    void updateWeights(gradient &gradients);
};

#endif // MODEL_HPP
