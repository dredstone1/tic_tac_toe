#ifndef VISUALIZERCONTROLLER
#define VISUALIZERCONTROLLER

#include "VisualizerRenderer.hpp"
#include <SFML/Graphics.hpp>
#include <atomic>
#include <mutex>
#include <thread>

namespace Visualizer {
class visualizerController {
  private:
	void update_display();
	mutex mtx;
	atomic<bool> running{false};
	VisualizerRenderer *renderer;
	void stop();
	void start(const neural_network &network);
	thread display_thread;
	void start_visuals(const neural_network &network);

  public:
	visualizerController(const neural_network &network);
	~visualizerController();
	void update(const neural_network &network);
	void update(const gradient &gradient);
};
} // namespace Visualizer

#endif // VISUALIZERCONTROLLER
