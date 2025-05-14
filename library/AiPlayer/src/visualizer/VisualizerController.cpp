#include "VisualizerController.hpp"

namespace Visualizer {

visualizerController::visualizerController(const neural_network &network) : visual(network) {
}

visualizerController::~visualizerController() {
	visual.stoptLoop();
}

} // namespace Visualizer
