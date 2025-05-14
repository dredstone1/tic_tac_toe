#include "display.hpp"

namespace Visualizer {
Display::Display() : window{sf::VideoMode::getDesktopMode(), "hello world"} {
}

void Display::Update() {
	window.clear(sf::Color::White);
	window.display();
}

void Display::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

} // namespace Visualizer
