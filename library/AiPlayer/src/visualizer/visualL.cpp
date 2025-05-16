#include "visualL.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <sstream>

namespace Visualizer {
visualL::visualL(Layer const &other, const int size_a) : Layer(other.getSize(), other.getPrevSize(), true) {
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

float visualL::calculateGap(const float size) {
	return (LAYER_HEIGHT - (size * NEURON_RADIUS * 2)) / (size + 1);
}

float visualL::calculateDistance(sf::Vector2f pos1, sf::Vector2f pos2) {
	return sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
}

float visualL::calculateAngle(sf::Vector2f pos1, sf::Vector2f pos2) {
	double angleRadians = atan2(pos2.y - pos1.y, pos2.x - pos1.x);
	double angleDegrees = angleRadians * 180.0 / M_PI;
	return angleDegrees;
}

void visualL::drawWeights(int neuron_i, sf::Vector2f pos, float prevGap) {
	for (int neuronP = 0; neuronP < getPrevSize(); neuronP++) {
		float xP = 0.f;
		float yP = prevGap + neuronP * (prevGap + NEURON_RADIUS * 2);

		float width = calculateDistance(pos, {xP, yP});
		float angle = calculateAngle({xP, yP}, pos);

		sf::RectangleShape line({width, 5 * (float)Parameters->weights[neuron_i][neuronP]});
		line.setFillColor(sf::Color::Black);
		line.setPosition(xP, yP + NEURON_RADIUS);
		line.setRotation(angle);
		layerRender.draw(line);
	}
}

void visualL::drawNeurons() {
	float gap = calculateGap(getSize());
	float prevGap = calculateGap(getPrevSize());

	for (int neuron = 0; neuron < getSize(); neuron++) {
		float x = LAYER_WIDTH - NEURON_RADIUS * 2;
		float y = gap + neuron * (gap + NEURON_RADIUS * 2);
		drawNeuron(dots.net[neuron], dots.out[neuron], {x, y});

		drawWeights(neuron, {x, y}, prevGap);
	}
}

void visualL::drawNeuron(const double input, const double output, sf::Vector2f pos) {
	sf::CircleShape shape(NEURON_RADIUS);
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(pos);

	sf::Font font;
	string path = string(RESOURCE_DIR) + "/Inter.ttc";
	if (!font.loadFromFile(path)) {
		return;
	}
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(10);
	ostringstream ss;
	ss << input;
	text.setString(ss.str());
	text.setFillColor(sf::Color::White);
	text.setPosition({pos.x + NEURON_RADIUS, pos.y + NEURON_RADIUS});
	layerRender.draw(shape);
	layerRender.draw(text);
}

void visualL::setDots(vector<double> out, vector<double> net) {
    dots.net = net;
    dots.out = out;
}
} // namespace Visualizer
