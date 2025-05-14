#ifndef VISUALIZER
#define VISUALIZER

#include "../model/neuralNetwork.hpp"
#include <SFML/Graphics.hpp>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace std;

namespace Visualizer {
class visualizer {
  private:
	neural_network &network;
	sf::RenderWindow window;
	thread renderThread;
	mutex mtx;
	condition_variable cv;

  public:
	void stop();
	void start();
	visualizer(neural_network &network);
	~visualizer() = default;
};
} // namespace Visualizer

#endif // VISUALIZER
