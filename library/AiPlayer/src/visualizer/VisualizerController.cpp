#include "VisualizerController.hpp"

namespace Visualizer {

visualizerController::visualizerController(const neural_network &network) : renderer(std::make_unique<VisualizerRenderer>(network)) {
	start();
}

visualizerController::~visualizerController() {
	stop();
}

void visualizerController::stop() {
	if (renderer) {
		renderer->stoptLoop();
	}
}

void visualizerController::start() {
	renderer->startLoop();
}

void visualizerController::update(const neural_network &network) {
	renderer->update(network);
}

void visualizerController::update(const gradient &gradient_) {
	renderer->update(gradient_);
}
} // namespace Visualizer
