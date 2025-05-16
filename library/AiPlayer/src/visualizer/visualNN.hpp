#ifndef VISUALNN
#define VISUALNN

#include "../model/neuralNetwork.hpp"
#include "../trainer/gradient.hpp"
#include "visualL.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

namespace Visualizer {
class visualNN {
  private:
	vector<visualL *> layers;
	gradient LocalGradient;

  public:
	visualNN(const neural_network &network);
	~visualNN() = default;
};
} // namespace Visualizer

#endif // VISUALNN
