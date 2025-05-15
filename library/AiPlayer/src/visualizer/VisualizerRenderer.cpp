#include "VisualizerRenderer.hpp"
#include <SFML/Window/Event.hpp>
#include <cstdio>

namespace Visualizer {
VisualizerRenderer::VisualizerRenderer(const neural_network &network) : LocalNetwork(network), LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count), window(sf::VideoMode(800, 600), "hello world") {
	renderLoop();
}

void VisualizerRenderer::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			close();
		if (event.type == sf::Event::Resized)
			needUpdate = true;
	}
}

void VisualizerRenderer::update() {
	window.clear(sf::Color::Red);
	window.display();
}

void VisualizerRenderer::renderLoop() {
	running = true;
	while (window.isOpen() && running) {
		processEvents();

		if (needUpdate) {
			update();
			needUpdate = false;
		}
	}

	window.close();
}

void VisualizerRenderer::update(const neural_network &new_network) {
	LocalNetwork.reset();
	for (int layer = 0; layer < LocalNetwork.getLayerCount(); layer++) {
	}

	needUpdate = true;
}

void VisualizerRenderer::update(const gradient &gradient_) {

	needUpdate = true;
}

void VisualizerRenderer::close() {
	running = false;
}

VisualizerRenderer::~VisualizerRenderer() {
	close();
}
} // namespace Visualizer
