#include "layer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

Layer::Layer(int _size, int _prev_size, LayerType _type,
             ActivationFunctions::ActivationFunctionType _activation)
    : activation_function(_activation) {
    type = _type;
    dots.resize(_size);
    weights = new vector<vector<double>>(_size, vector<double>(_prev_size, 0.0));

    for (auto &neuron_weights : *weights) {
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> dist(0.0, sqrt(2.0 / (neuron_weights.size())));
        for (auto &weight : neuron_weights) {
            weight = dist(gen);
            // weight = 0.5;
        }
    }
}

void Layer::print_activations(const vector<neuron> &activations) {
    double min_val = activations[0].out, max_val = activations[0].out,
           sum = 0.0;
    for (auto val : activations) {
        min_val = min(min_val, val.out);
        max_val = max(max_val, val.out);
        sum += val.out;
    }
    double mean = sum / activations.size();

    double sq_sum = 0.0;
    for (auto val : activations) {
        sq_sum += (val.out - mean) * (val.out - mean);
    }
    double std_dev = sqrt(sq_sum / activations.size());

    cout << "Activations: Min=" << min_val << ", Max=" << max_val
         << ", Mean=" << mean << ", StdDev=" << std_dev << endl;
}

void Layer::forward(vector<neuron> metrix) {
    if (type == LayerType::INPUT) {
        dots = metrix;
    } else {
        for (int i = 0; i < dots.size(); ++i) {
            dots[i].net = 0.0;
            for (int j = 0; j < metrix.size(); ++j) {
                dots[i].out = dots[i].net +=
                    (*weights)[i][j] * metrix[j].out;
            }
        }
    }

    activation_function.activate(dots);
}

vector<double> Layer::getNet() {
    vector<double> net;
    for (auto &dot : dots) {
        net.push_back(dot.net);
    }
    return net;
}

vector<double> Layer::getOut() {
    vector<double> out;
    for (auto &dot : dots) {
        out.push_back(dot.out);
    }
    return out;
}

ActivationFunctions::ActivationFunctionType Layer::getActivation() {
    return activation_function.getType();
}

void Layer::updateWeights(gradient_layer const &new_weights) {
    for (int i = 0; i < getSize(); i++) {
        for (int j = 0; j < getPrevSize(); j++) {
            (*weights)[i][j] += new_weights.weights[i][j];
        }
    }
}

Layer::Layer(Layer const &other) : activation_function(other.activation_function) {
    type = other.type;
    weights = other.weights;
    dots.resize(other.dots.size());
}
