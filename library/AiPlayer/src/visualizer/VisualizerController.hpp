#ifndef VISUALIZERCONTROLLER
#define VISUALIZERCONTROLLER

#include "VisualizerRenderer.hpp"
#include <SFML/Graphics.hpp>

namespace Visualizer {
class visualizerController {
  private:
	sf::RenderWindow window;
	void update_display();
	VisualizerRenderer visual;

  public:
	visualizerController(const neural_network &network);
	~visualizerController();
	void update(const neural_network &network);
	void update(const gradient &gradient);
};
} // namespace Visualizer

#endif // VISUALIZERCONTROLLER
