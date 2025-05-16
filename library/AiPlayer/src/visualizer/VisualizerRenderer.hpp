#ifndef VISUALIZER
#define VISUALIZER

#include "visualNN.hpp"
#include <SFML/Graphics.hpp>
#include <atomic>

using namespace std;

namespace Visualizer {
class VisualizerRenderer {
  private:
	sf::RenderWindow window;
	visualNN visualNetwork;
	atomic<bool> needUpdate{true};
	atomic<bool> running{false};
	void update();
	void renderLoop();
	void processEvents();
	void renderObjects();

  public:
	VisualizerRenderer(const neural_network &network);
	~VisualizerRenderer();
	void close();
};
} // namespace Visualizer
#endif
