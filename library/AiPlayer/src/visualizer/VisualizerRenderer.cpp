#include "VisualizerRenderer.hpp"
#include "visualNN.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <cstdio>

namespace Visualizer {
VisualizerRenderer::VisualizerRenderer(const neural_network &network) : window(sf::VideoMode(1600, 800), "Visualizer", sf::Style::Titlebar | sf::Style::Titlebar), visualNetwork(network) {
	renderLoop();
}

void VisualizerRenderer::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			close();
		if (event.type == sf::Event::Resized) {
			needUpdate = true;
		}
	}
}

void VisualizerRenderer::renderObjects() {
	visualNetwork.render();

	sf::Sprite visualNetworkSprite = visualNetwork.getSprite();
	visualNetworkSprite.setPosition(50, 50);

	window.draw(visualNetworkSprite);
}

void VisualizerRenderer::update() {
	window.clear(sf::Color::White);

	renderObjects();

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

void VisualizerRenderer::close() {
	running = false;
}

VisualizerRenderer::~VisualizerRenderer() {
	close();
}
} // namespace Visualizer
