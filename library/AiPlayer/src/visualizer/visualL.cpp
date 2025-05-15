#include "visualL.hpp"

namespace Visualizer {
visualL::visualL(Layer const &other) : Layer(other.getSize(), other.getPrevSize()) {
	dots = other.getDots();
}
} // namespace Visualizer
