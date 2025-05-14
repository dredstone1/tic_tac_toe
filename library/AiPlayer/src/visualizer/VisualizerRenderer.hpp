#ifndef VISUALIZER
#define VISUALIZER

#include "../model/neuralNetwork.hpp"
#include "../trainer/gradient.hpp"
#include "display.hpp"
#include <atomic>
#include <mutex>
#include <thread>

using namespace std;

namespace Visualizer {
class VisualizerRenderer {
  private:
	thread display_thread;
	mutex mtx;
	atomic<bool> running_{false};
	atomic<bool> needUpdate{false};
	void Update();
	neural_network LocalNetwork;
	Display display;
	gradient LocalGradient;
	void renderLoop();
	void processEvents();

  public:
	VisualizerRenderer(const neural_network &network);
	void startLoop();
	void stoptLoop();
	void update(const neural_network &network);
	void update(const gradient &gradient);
};
} // namespace Visualizer

#endif
