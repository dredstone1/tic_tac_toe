#include "VisualizerController.hpp"
#include "VisualizerRenderer.hpp"

namespace Visualizer {

visualizerController::visualizerController(const neural_network &network) {
	start(network);
}

visualizerController::~visualizerController() {
	stop();
}

void visualizerController::stop() {
	running = false;
	if (renderer) {
		renderer->close();
	}
}

void visualizerController::start(const neural_network &network) {
	if (running)
		return;

	running = true;
	display_thread = thread(&visualizerController::start_visuals, this, std::cref(network));
}

void visualizerController::start_visuals(const neural_network &network) {
	running = true;
	renderer = new VisualizerRenderer(network);
	delete renderer;
	running = false;
}

void visualizerController::update(const neural_network &network) {
	if (renderer) {
	}
}

void visualizerController::updateDots(const int layer, vector<double> out, vector<double> net) {
	if (renderer) {
	}
}

void visualizerController::update(const gradient &gradient_) {
	if (renderer) {
	}
}
} // namespace Visualizer
