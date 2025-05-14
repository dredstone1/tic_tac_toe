#ifndef DISPLAY
#define DISPLAY

#include <SFML/Graphics.hpp>

namespace Visualizer {
class Display {
  private:
	sf::RenderWindow mWindow;

  public:
	Display();
	~Display() = default;
	void Update();
	void run();
	int isOpen() { return mWindow.isOpen(); }
};
} // namespace Visualizer

#endif
