#include "display.hpp"

namespace Visualizer {
Display::Display() : mWindow{sf::VideoMode(800, 600), "hello world"} {
}

void Display::Update() {
	mWindow.clear(sf::Color::Red);
	mWindow.display();
}

void Display::handleEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

} // namespace Visualizer
