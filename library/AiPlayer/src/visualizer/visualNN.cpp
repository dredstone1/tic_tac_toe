#include "visualNN.hpp"
#include <bits/types/locale_t.h>

namespace Visualizer {
visualNN::visualNN(const neural_network &network) : LocalGradient(network.input_size, network.output_size, network.hidden_layers_size, network.hidden_layers_count) {
	layers.reserve(network.getLayerCount());

	for (int layer = 0; layer < network.getLayerCount(); layer++) {
		layers.push_back(new visualL(*network.layers[layer]));
	}
}
} // namespace Visualizer
