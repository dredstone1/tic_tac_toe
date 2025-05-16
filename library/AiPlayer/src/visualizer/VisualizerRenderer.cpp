#include "VisualizerRenderer.hpp"
#include "visualNN.hpp"
#include <SFML/Window/Event.hpp>
#include <cstdio>

namespace Visualizer {
VisualizerRenderer::VisualizerRenderer(const neural_network &network) : window(sf::VideoMode(800, 600), ""), visualNetwork(network) {
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

void VisualizerRenderer::renderObjects() {
	// sf::Font font;
	// string path = string(RESOURCE_DIR) + "/Inter.ttc";
	// if (!font.loadFromFile(path)) {
	// 	return;
	// }
	// sf::Text text;
	// text.setFont(font);
	// text.setString("Hello, SFML!");
	// text.setCharacterSize(48);
	// text.setFillColor(sf::Color::Black);
	// text.setPosition(100.f, 100.f);
	// window.draw(text);
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

void VisualizerRenderer::update(const neural_network &new_network) {

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
