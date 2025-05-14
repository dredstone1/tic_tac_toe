#include "VisualizerRenderer.hpp"
#include "display.hpp"

namespace Visualizer {
VisualizerRenderer::VisualizerRenderer(const neural_network &network) : LocalNetwork(network), LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count) {}

void VisualizerRenderer::startLoop() {
	running_ = true;
	display_thread = std::thread(&VisualizerRenderer::renderLoop, this);
}

void VisualizerRenderer::stoptLoop() {
	running_ = false;
	if (display_thread.joinable()) {
		display_thread.join();
	}
}

void VisualizerRenderer::processEvents() {
}

void VisualizerRenderer::Update() {
	if (needUpdate) {
	}

	needUpdate = false;
}

void VisualizerRenderer::renderLoop() {
	while (display.isOpen()) {
		processEvents();

		Update();
	}
}

void VisualizerRenderer::update(const neural_network &network) {

	needUpdate = true;
}

void VisualizerRenderer::update(const gradient &gradient_) {

	needUpdate = true;
}
} // namespace Visualizer
