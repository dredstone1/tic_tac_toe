#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
using namespace std;
enum LayerType { INPUT, HIDDEN, OUTPUT };

class Layer {
  private:
    LayerType _type;
    void (*activation)(vector<double> &metrix);
    vector<vector<double>> weights;
    vector<double> dots;
    double getRandWeights();

  public:
    Layer(int size, int prev_size, LayerType type,
          void (*activations)(vector<double> &metrix));
    LayerType getType() { return _type; }
    int getSize() { return dots.size(); }
    vector<double> getDots() { return dots; }
    void forward(vector<double> metrix);
    ~Layer() = default;
};

#endif // LAYER_HPP
