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
#define NN_WIDTH 1500
#define NN_HEIGHT 700

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
};
} // namespace Visualizer

#endif // VISUALNN
