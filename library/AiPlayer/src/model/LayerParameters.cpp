#include "LayerParameters.hpp"
#include <cmath>
#include <random>
#include <vector>

LayerParameters::LayerParameters(const int size, const int prev_size, const bool random) {
	weights.resize(size, vector<double>(prev_size, 0.5));
	bias.resize(size, BIAS_INIT);

	if (!random)
		return;

	random_device rd;
	mt19937 gen(rd());
	normal_distribution<> dist(0.0, sqrt(2.0 / (prev_size)));

	for (auto &dot : weights) {
		for (auto &weight : dot) {
			double random_value = dist(gen);
			random_value = fmin(fmax(random_value, -1.0), 1.0);
			random_value = round(random_value * 10000.0) / 10000.0;
			weight = random_value;
			// weight = 0.5;
		}
	}
}

void LayerParameters::reset() {
	for (int i = 0; i < getSize(); i++) {
		bias[i] = 0.0;

		for (int j = 0; j < getPrevSize(); j++) {
			weights[i][j] = 0.0;
		}
	}
}

void LayerParameters::add(const LayerParameters &new_gradient_layer) {
	for (int i = 0; i < getSize(); i++) {
		bias[i] += new_gradient_layer.bias[i];

		for (int j = 0; j < getPrevSize(); j++) {
			weights[i][j] += new_gradient_layer.weights[i][j];
		}
	}
}

void LayerParameters::multiply(const double value) {
	for (int i = 0; i < getSize(); i++) {
		bias[i] *= value;

		for (int j = 0; j < getPrevSize(); j++) {
			weights[i][j] *= value;
		}
	}
}

LayerParameters::LayerParameters(LayerParameters const &other) : weights(other.weights), bias(other.bias) {}
