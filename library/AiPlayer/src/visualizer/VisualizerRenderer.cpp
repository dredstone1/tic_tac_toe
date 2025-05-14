#include "VisualizerRenderer.hpp"

namespace Visualizer {
VisualizerRenderer::VisualizerRenderer(const neural_network &network) : LocalNetwork(network), LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count) {
}

void VisualizerRenderer::startLoop() {
	running_ = true;
}

void VisualizerRenderer::stoptLoop() {
	running_ = false;
}
} // namespace Visualizer
