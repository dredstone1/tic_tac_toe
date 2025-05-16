#ifndef VISUALNN
#define VISUALNN

#include "../model/neuralNetwork.hpp"
#include "../trainer/gradient.hpp"
#include "visualL.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

using namespace std;

namespace Visualizer {

class visualNN {
  private:
	vector<visualL *> layers;
	const int NnLength;
	gradient LocalGradient;
	sf::RenderTexture NNRender;
	void createNnVisual();
	void clear();
	void display();
	void renderLayers();

  public:
	visualNN(const neural_network &network);
	~visualNN() = default;
	sf::Sprite getSprite();
	void render();
	void updateDots(const int layer, vector<double> out, vector<double> net);
};
} // namespace Visualizer

#endif // VISUALNN
