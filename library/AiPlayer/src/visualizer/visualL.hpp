#ifndef VISUALL
#define VISUALL

#include "../model/Layers/layer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace Visualizer {
#define LAYER_WIDTH 100
#define LAYER_HEIGHT 700
#define NEURON_RADIUS 20.f
#define NN_WIDTH 1500

class visualL : public Layer {
  private:
	sf::RenderTexture layerRender;
	void createLayerVisual(const int size_a);
	void clear();
	void display();
	void drawNeuron(const double input, const double output, sf::Vector2f pos);
	void drawNeurons();

  public:
	visualL(int _size, int _prev_size, const int size_a);
	visualL(Layer const &other, const int size_a);
	LayerType getType() const override { return LayerType::NONE; }
	sf::Sprite getSprite();
	void renderLayer();
};
} // namespace Visualizer

#endif // VISUALL
