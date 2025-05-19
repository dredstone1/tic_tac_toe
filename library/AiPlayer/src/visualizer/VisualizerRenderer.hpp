#ifndef VISUALIZER
#define VISUALIZER

#include "VInterface.hpp"
#include "state.hpp"
#include "visualNN.hpp"
#include <SFML/Graphics.hpp>
#include <atomic>
#include <climits>

using namespace std;

namespace Visualizer {
class VisualizerRenderer {
  private:
	sf::RenderWindow window;
	visualNN visualNetwork;
	vInteface interface;
	atomic<int> needUpdate{true};
	long updatedLayersDot = LONG_MAX;
	long updatedLayersWeight = LONG_MAX;
	atomic<bool> running{false};
	state *Vstate;
	void update();
	void renderLoop();
	void processEvents();
	void renderObjects();
	void setUpdate(int Dot, int Weight);

  public:
	VisualizerRenderer(const neural_network &network, state *vstate);
	~VisualizerRenderer();
	void close();
	void updateDots(const int layer, vector<double> out, vector<double> net);
	bool updateStatus() { return needUpdate; }
	void start();
	void update(const int layer, const LayerParameters &gradients);
};
} // namespace Visualizer
#endif
