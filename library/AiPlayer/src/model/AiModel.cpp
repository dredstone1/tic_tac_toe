#include "../include/AiPlayer/AiModel.hpp"
#include "layer.hpp"
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

void print(std::vector<double> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << ' ';
    }
}

AiModel::AiModel() {
    this->_model = new model(9, 9, 33, 3,
                             ActivationFunctions::ActivationFunctionType::RELU);
}

AiModel::AiModel(string file_name) { this->load(file_name); }

int AiModel::load(string file_name) {
    ifstream file(file_name + ".model");

    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    string line;
    getline(file, line);
    file.close();
    char *line_ = &line[0];
    int hidden_layers_count = atoi(strtok(line_, " ")) - 2;
    ActivationFunctions::ActivationFunctionType activation =
        (ActivationFunctions::ActivationFunctionType)atoi(
            line_ = strtok(NULL, " "));
    int input_size = atoi(strtok(NULL, " "));
    int hidden_layers_size = atoi(strtok(NULL, " "));
    int output_size = atoi(strtok(NULL, " "));

    if (this->_model) {
        delete this->_model;
    }
    this->_model = new model(input_size, output_size, hidden_layers_size,
                             hidden_layers_count, activation);

    for (int i = 0; i < this->_model->getLayerCount(); i++) {
        if (this->_model->getLayer(i).getType() == LayerType::INPUT) {
            continue;
        }

        for (int j = 0; j < this->_model->getLayer(i).getSize(); j++) {
            for (int k = 0; k < this->_model->getLayer(i - 1).getSize(); k++) {
                this->_model->getLayer(i).setWeight(j, k,
                                                    atof(strtok(NULL, " ")));
            }
        }
    }

    return 0;
}

int AiModel::save(string file_name) {
    ofstream file(file_name + ".model");
    file << std::fixed << std::setprecision(3) << this->_model->getLayerCount()
         << " " << this->_model->getLayer(1).getActivation() << " "
         << this->_model->getLayer(0).getSize() << " "
         << this->_model->getLayer(1).getSize() << " "
         << this->_model->getLayer(this->_model->getLayerCount() - 1).getSize()
         << " ";

    for (int i = 0; i < this->_model->getLayerCount(); i++) {
        if (this->_model->getLayer(i).getType() == LayerType::INPUT) {
            continue;
        }

        for (int j = 0; j < this->_model->getLayer(i).getSize(); j++) {
            for (int k = 0; k < this->_model->getLayer(i - 1).getSize(); k++) {
                file << this->_model->getLayer(i).getWeight(j, k) << " ";
            }
        }
    }

    file.close();
    return 0;
}

int AiModel::run_model(std::vector<double> &input) {
    return this->_model->run_model(input);
}

int AiModel::getPrediction(std::vector<double> &input) {
    int i, max = i = std::find(input.begin(), input.end(), 0.5) - input.begin();
    while (++i < input.size()) {
        if (this->_model->getOutput()[i] > this->_model->getOutput()[max] &&
            input[i] == 0.5) {
            max = i;
        }
    }

    int best = 0;
    for (int i = 0; i < 9; i++) {
        if (this->_model->getOutput()[i] > this->_model->getOutput()[best]) {
            best = i;
        }
    }

    if (input[best] == 0.5) {
        std::cout << "error" << std::endl;
    }

    return max;
}

AiModel::~AiModel() { delete this->_model; }
