#ifndef MODEL_HPP
#define MODEL_HPP

#include "layer.hpp"

#define FIX_LAYER_COUNT 2

typedef vector<vector<vector<double>>> Gradient;

class model {
  private:
    vector<Layer> layers;

  public:
    model(int input_size, int output_size, int hidden_layers_size,
          int hidden_layers_count,
          ActivationFunctions::ActivationFunctionType activations);
    ~model() = default;
    int run_model(vector<double> &input);
    vector<double> getOutput();
    void reset();
    int getLayerCount() { return this->layers.size(); }
    Layer &getLayer(int i) { return this->layers.at(i); }
};

#endif // MODEL_HPP
