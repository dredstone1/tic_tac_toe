#include "visualL.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace Visualizer {
visualL::visualL(Layer const &other) : Layer(other.getSize(), other.getPrevSize()) {
	createLayerVisual();
}

void visualL::createLayerVisual() {
	layerRender.create(50, 500);
}

void visualL::display() {
	layerRender.display();
}

void visualL::clear() {
	layerRender.clear(sf::Color::Green);
}

void visualL::renderLayer() {
	clear();
}

sf::Sprite visualL::getSprite() {
	display();
	return sf::Sprite(layerRender.getTexture());
}

} // namespace Visualizer
