#ifndef DISPLAY
#define DISPLAY

#include <SFML/Graphics.hpp>

namespace Visualizer {
class Display {
  private:
	sf::RenderWindow window;

  public:
	Display();
	~Display() = default;
	void Update();
	void run();
    void handleEvents();
	int isOpen() { return window.isOpen(); }
};
} // namespace Visualizer

#endif
