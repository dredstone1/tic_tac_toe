#include "../include/AiPlayer/AiModel.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<double> a) {
    std::cout << "The vector elements are : ";

    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
}

AiModel::AiModel() { std::cout << "Creating AI Model" << std::endl; }

int AiModel::basic_setup() {
    std::cout << "Setting up AI" << std::endl;

    if (this->_model != nullptr) {
        delete this->_model;
    }
    this->_model = new model(9, 9, 36, 2);

    return 0;
}

int AiModel::load() {
    std::cout << "Loading AI" << std::endl;

    return 0;
}

AiModel::~AiModel() {
    if (this->_model != nullptr) {
        delete this->_model;
        this->_model = nullptr;
    }
}

int AiModel::run_model(std::vector<double> &input) {
    std::cout << "Running AI" << std::endl;
    this->_model->run_model(input);
    return 0;
}

int AiModel::getPrediction(std::vector<double> &input) {
    // std::cout << "Output: ";
    // print(this->_model->getOutput());
    // std::cout << std::endl;

    int i, max = i = std::find(input.begin(), input.end(), 0.5) - input.begin();
    while (++i < input.size()) {
        if (this->_model->getOutput()[i] > this->_model->getOutput()[max] &&
            input[i] == 0.5) {
            max = i;
        }
    }
    return max;
}
