#ifndef VISUALL
#define VISUALL

#include "../model/Layers/layer.hpp"
#include <SFML/Graphics.hpp>

namespace Visualizer {
class visualL : public Layer {
  public:
	visualL(int _size, int _prev_size) : Layer(_size, _prev_size, true) {}
	visualL(Layer const &other);
	LayerType getType() const override { return LayerType::NONE; }
};
} // namespace Visualizer

#endif // VISUALL
