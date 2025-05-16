#ifndef VISUALL
#define VISUALL

#include "../model/Layers/layer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace Visualizer {
class visualL : public Layer {
  private:
	sf::RenderTexture layerRender;
	void createLayerVisual();
	void clear();
	void display();

  public:
	visualL(int _size, int _prev_size) : Layer(_size, _prev_size, true) {}
	visualL(Layer const &other);
	LayerType getType() const override { return LayerType::NONE; }
	sf::Sprite getSprite();
	void renderLayer();
};
} // namespace Visualizer

#endif // VISUALL
