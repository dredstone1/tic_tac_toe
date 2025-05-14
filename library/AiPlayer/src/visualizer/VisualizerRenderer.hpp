#ifndef VISUALIZER
#define VISUALIZER

#include "../model/neuralNetwork.hpp"
#include "../trainer/gradient.hpp"
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

	neural_network LocalNetwork;
	gradient LocalGradient;

  public:
	VisualizerRenderer(const neural_network &network);
	void startLoop();
	void stoptLoop();
};
} // namespace Visualizer

#endif
