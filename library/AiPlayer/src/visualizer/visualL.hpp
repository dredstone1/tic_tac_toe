#ifndef VISUALL
#define VISUALL

#include "../model/Layers/layer.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace Visualizer {
#define NN_HEIGHT 700
#define NEURON_RADIUS 20.f
#define NN_WIDTH 1000

class visualL : public Layer {
  private:
	sf::RenderTexture layerRender;
	void createLayerVisual(const int size_a);
	void clear();
	void display();
	void drawNeuron(const double input, const double output, sf::Vector2f pos);
	void drawNeurons();
	void drawWeights(int neuron_i, sf::Vector2f pos, float prevGap);
	static float calculateGap(const float size);
	static float calculateDistance(sf::Vector2f pos1, sf::Vector2f pos2);
	static float calculateAngle(sf::Vector2f pos1, sf::Vector2f pos2);
	static const float calculateWIDTH(const int size_a, const bool is_params);

  public:
	visualL(int _size, int _prev_size, const int size_a);
	visualL(Layer const &other, const int size_a);
	LayerType getType() const override { return LayerType::NONE; }
	sf::Sprite getSprite();
	void renderLayer();
	void setDots(vector<double> out, vector<double> net);
	const bool is_params;
	const float WIDTH;
};
} // namespace Visualizer

#endif // VISUALL
