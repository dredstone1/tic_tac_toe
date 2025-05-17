#include "visualNN.hpp"
#include "visualL.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <bits/types/locale_t.h>
#include <cstdio>

namespace Visualizer {
visualNN::visualNN(const neural_network &network) : LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count), NnLength(network.getLayerCount() + 1) {
	layers.reserve(network.getLayerCount() + 1);

	layers.push_back(new visualL(network.input_size, 0, network.getLayerCount() + 1));
	for (int layer = 0; layer < network.getLayerCount(); layer++) {
		layers.push_back(new visualL(*network.layers[layer], network.getLayerCount() + 1));
	}

	createNnVisual();
}

void visualNN::createNnVisual() {
	NNRender.create(NN_WIDTH, LAYER_HEIGHT);
}

void visualNN::display() {
	NNRender.display();
}

void visualNN::clear() {
	NNRender.clear(sf::Color::Red);
}

void visualNN::renderLayers() {
	for (int layer = 0; layer < NnLength; layer++) {
		layers[layer]->renderLayer();
		sf::Sprite newSprite = layers[layer]->getSprite();
		newSprite.setPosition(layer * LAYER_WIDTH, 0);
		NNRender.draw(newSprite);
	}
}

void visualNN::render() {
	clear();
	renderLayers();
}

sf::Sprite visualNN::getSprite() {
	display();
	return sf::Sprite(NNRender.getTexture());
}

void visualNN::updateDots(const int layer, vector<double> out, vector<double> net) {
	layers[layer]->setDots(out, net);
}

void visualNN::update(const int layer, const LayerParameters &gradients) {
	layers[layer]->add(gradients);
}

} // namespace Visualizer
