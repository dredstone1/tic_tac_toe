#include "Output_Layer.hpp"
#include "../activations.hpp"

void Output_Layer::forward(const vector<double> &metrix) {
	for (int i = 0; i < dots.size(); i++) {
		// dots.net[i] = Parameters->bias[i];

		for (int j = 0; j < metrix.size(); j++) {
			dots.net[i] += Parameters->weights[i][j] * metrix[j];
		}
	}

	ActivationFunctions::Softmax(dots);
}
