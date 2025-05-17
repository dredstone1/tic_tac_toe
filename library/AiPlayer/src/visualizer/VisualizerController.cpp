#include "VisualizerController.hpp"
#include "VisualizerRenderer.hpp"
#include <cstdio>
#include <thread>

namespace Visualizer {

visualizerController::visualizerController(const neural_network &network) {
	printf("start Visualizer\n");
	start(network);
}

visualizerController::~visualizerController() {
	stop();
}

void visualizerController::stop() {
	running = false;
	if (display_thread.joinable()) {
		if (renderer) {
			renderer->close();
		}
		display_thread.join();
	}
}

void visualizerController::start(const neural_network &network) {
	if (running)
		return;

	display_thread = thread(&visualizerController::start_visuals, this, cref(network));
	while (!renderer) {
		std::this_thread::sleep_for(1ms);
	}
}

void visualizerController::start_visuals(const neural_network &network) {
	renderer = new VisualizerRenderer(network);
	if (!renderer)
		return;

	running = true;
	renderer->start();
	delete renderer;
	running = false;
}

void visualizerController::update(const neural_network &network) {
	if (renderer) {
	}
}

void visualizerController::updateDots(const int layer, vector<double> out, vector<double> net) {
	if (renderer) {
		renderer->updateDots(layer, out, net);
	}
}

void visualizerController::update(const int layer, const LayerParameters &gradient_) {
	if (renderer) {
		renderer->update(layer, gradient_);
	}
}
} // namespace Visualizer
