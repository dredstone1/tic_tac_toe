#ifndef MODEL_HPP
#define MODEL_HPP

#include "layer.hpp"

#define FIX_LAYER_COUNT 2 // one for input and one for output.

class model {
  private:
    vector<Layer> layers;

  public:
    model(int input_size, int output_size, int hidden_layers_size,
          int hidden_layers_count);
    ~model() = default;
};

#endif // MODEL_HPP
