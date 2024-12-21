#include "../include/AiPlayer/AiModel.hpp"
#include "layer.hpp"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

void print(vector<double> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }
}

AiModel::AiModel() {
    this->_model = new model(
        9, 9, 32, 4, ActivationFunctions::ActivationFunctionType::RELU_LEAKY);
}

AiModel::AiModel(string file_name) { this->load(file_name); }

int AiModel::load(string file_name) {
    ifstream file(file_name + ".model");

    if (!file.is_open()) {
        cout << "File not found" << endl;
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

        for (int j = 0; j < this->_model->getLayer(i).getDots().size(); j++) {
            for (int k = 0; k < this->_model->getLayer(i - 1).getDots().size();
                 k++) {
                this->_model->getLayer(i).setWeight(j, k,
                                                    atof(strtok(NULL, " ")));
            }
        }
    }

    return 0;
}

int AiModel::save(string file_name) {
    ofstream file(file_name + ".model");
    file << fixed << setprecision(3) << this->_model->getLayerCount() << " "
         << this->_model->getLayer(1).getActivation() << " "
         << this->_model->getLayer(0).getDots().size() << " "
         << this->_model->getLayer(1).getDots().size() << " "
         << this->_model->getLayer(this->_model->getLayerCount() - 1)
                .getDots()
                .size()
         << " ";

    for (int i = 0; i < this->_model->getLayerCount(); i++) {
        if (this->_model->getLayer(i).getType() == LayerType::INPUT) {
            continue;
        }

        for (int j = 0; j < this->_model->getLayer(i).getDots().size(); j++) {
            for (int k = 0; k < this->_model->getLayer(i - 1).getDots().size();
                 k++) {
                file << this->_model->getLayer(i).getWeight(j, k) << " ";
            }
        }
    }

    file.close();
    return 0;
}

int AiModel::run_model(vector<double> &input) {
    return this->_model->run_model(input);
}

int AiModel::getPrediction(vector<double> &input) {
    int max1 = 0, max = 0;
    for (int i = 0; i < 9; i++) {
        if (this->_model->getOutput()[max1] < this->_model->getOutput()[i]) {
            max1 = i;
        }
    }

    if (input[max1] != 0.5) {
        cout << "error 1: " << this->_model->getOutput()[max1] << endl;
    }

    while (input[max1] != 0.5) {
        if (max1 == 8 || max == 1) {
            max1--;
            max = 1;
            continue;
        }
        max1++;
    }

    return max1;
}

AiModel::~AiModel() { delete this->_model; }
