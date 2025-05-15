#ifndef VISUALIZER
#define VISUALIZER

#include "../model/neuralNetwork.hpp"
#include "../trainer/gradient.hpp"
#include <SFML/Graphics.hpp>
#include <atomic>

using namespace std;

namespace Visualizer {
class VisualizerRenderer {
  private:
	sf::RenderWindow window;
	neural_network LocalNetwork;
	atomic<bool> needUpdate{true};
	atomic<bool> running{false};
    void update();
	gradient LocalGradient;
	void renderLoop();
	void processEvents();

  public:
	VisualizerRenderer(const neural_network &network);
	~VisualizerRenderer();
	void update(const neural_network &network);
	void update(const gradient &gradient);
	void close();
};
} // namespace Visualizer

#endif
