#include "visualL.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

namespace Visualizer {
visualL::visualL(Layer const &other, const int size_a) : Layer(other.getSize(), other.getPrevSize()) {
	createLayerVisual(size_a);
}
visualL::visualL(int _size, int _prev_size, const int size_a) : Layer(_size, _prev_size) {
	createLayerVisual(size_a);
}

void visualL::createLayerVisual(const int size_a) {
	layerRender.create(NN_WIDTH / size_a, LAYER_HEIGHT);
}

void visualL::display() {
	layerRender.display();
}

void visualL::clear() {
	layerRender.clear(sf::Color::Green);
}

void visualL::renderLayer() {
	clear();
	drawNeurons();
}

sf::Sprite visualL::getSprite() {
	display();
	return sf::Sprite(layerRender.getTexture());
}

void visualL::drawNeurons() {
	float gap = (LAYER_HEIGHT - (getSize() * NEURON_RADIUS)) / (getSize() + 1);
	for (int neuron = 0; neuron < getSize(); neuron++) {
		drawNeuron(dots.net[neuron], dots.out[neuron], {LAYER_WIDTH - NEURON_RADIUS * 2, (gap) + neuron * (gap + NEURON_RADIUS)});
	}
}

void visualL::drawNeuron(const double input, const double output, sf::Vector2f pos) {
	sf::CircleShape shape(NEURON_RADIUS);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(pos);

	layerRender.draw(shape);
}

} // namespace Visualizer
