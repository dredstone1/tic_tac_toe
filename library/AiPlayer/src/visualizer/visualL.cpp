#include "visualL.hpp"

namespace Visualizer {
visualL::visualL(Layer const &other) : Layer(other.getSize(), other.getPrevSize()) {
}
} // namespace Visualizer
