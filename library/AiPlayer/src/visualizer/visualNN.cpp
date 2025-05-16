#include "visualNN.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <bits/types/locale_t.h>

namespace Visualizer {
visualNN::visualNN(const neural_network &network) : LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count), NnLength(network.getLayerCount()) {
	layers.reserve(network.getLayerCount());

	for (int layer = 0; layer < network.getLayerCount(); layer++) {
		layers.push_back(new visualL(*network.layers[layer]));
	}

	createNnVisual();
}

void visualNN::createNnVisual() {
	NNRender.create(NNwidth, NNwidth);
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
		NNRender.draw(layers[layer]->getSprite());
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
} // namespace Visualizer
