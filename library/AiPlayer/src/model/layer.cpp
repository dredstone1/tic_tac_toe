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
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dist(
            0.0, std::sqrt(2.0 / (neuron_weights.size())));
        for (auto &weight : neuron_weights) {
            weight = dist(gen);
        }
    }
}

void Layer::print_activations(const std::vector<neuron> &activations) {
    double min_val = activations[0].out, max_val = activations[0].out,
           sum = 0.0;
    for (auto val : activations) {
        min_val = std::min(min_val, val.out);
        max_val = std::max(max_val, val.out);
        sum += val.out;
    }
    double mean = sum / activations.size();

    double sq_sum = 0.0;
    for (auto val : activations) {
        sq_sum += (val.out - mean) * (val.out - mean);
    }
    double std_dev = std::sqrt(sq_sum / activations.size());

    std::cout << "Activations: Min=" << min_val << ", Max=" << max_val
              << ", Mean=" << mean << ", StdDev=" << std_dev << std::endl;
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

