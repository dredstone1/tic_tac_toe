#include "layer.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

Layer::Layer(int size, int prev_size, LayerType type,
             ActivationFunctions::ActivationFunctionType activation)
    : activation_function(activation) {
    this->_type = type;
    this->dots.resize(size);
    this->weights.resize(size, vector<double>(prev_size, 0.0));

    for (auto &neuron_weights : weights) {
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<> dist(0.0, sqrt(2.0 / (neuron_weights.size())));
        for (auto &weight : neuron_weights) {
            weight = dist(gen);
            // weight = 0.01;
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
    if (this->_type == LayerType::INPUT) {
        this->dots = metrix;
    } else {
        for (int i = 0; i < this->dots.size(); ++i) {
            this->dots[i].net = 0.0;
            for (int j = 0; j < metrix.size(); ++j) {
                this->dots[i].out = this->dots[i].net +=
                    this->weights[i][j] * metrix[j].out;
            }
        }
    }

    this->activation_function.activate(this->dots);
    // print_activations(this->dots);
}

vector<double> Layer::getNet() {
    vector<double> net;
    for (auto &dot : this->dots) {
        net.push_back(dot.net);
    }
    return net;
}

vector<double> Layer::getOut() {
    vector<double> out;
    for (auto &dot : this->dots) {
        out.push_back(dot.out);
    }
    return out;
}

ActivationFunctions::ActivationFunctionType Layer::getActivation() {
    return activation_function.getType();
}

void Layer::updateWeights(vector<vector<double>> &new_weights) {
    for (int i = 0; i < this->weights.size(); i++) {
        for (int j = 0; j < this->weights[i].size(); j++) {
            this->weights[i][j] += new_weights[i][j];
        }
    }
}
