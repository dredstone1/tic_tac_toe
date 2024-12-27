#include "../include/AiPlayer/AiModel.hpp"
#include "layer.hpp"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

AiModel::AiModel() {
    _model = new model(
        9, 9, 32, 2, ActivationFunctions::ActivationFunctionType::RELU_LEAKY);
}

AiModel::AiModel(string _file_name) { load(_file_name); }

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

    if (_model) {
        delete _model;
    }
    _model = new model(input_size, output_size, hidden_layers_size,
                             hidden_layers_count, activation);

    for (int i = 0; i < _model->getLayerCount(); i++) {
        if (_model->getLayer(i).getType() == LayerType::INPUT) {
            continue;
        }

        for (int j = 0; j < _model->getLayer(i).getDots().size(); j++) {
            for (int k = 0; k < _model->getLayer(i - 1).getDots().size();
                 k++) {
                _model->getLayer(i).setWeight(j, k,
                                                    atof(strtok(NULL, " ")));
            }
        }
    }

    return 0;
}

int AiModel::save(string file_name) {
    ofstream file(file_name + ".model");
    file << fixed << setprecision(3) << _model->getLayerCount() << " "
         << _model->getLayer(1).getActivation() << " "
         << _model->getLayer(0).getDots().size() << " "
         << _model->getLayer(1).getDots().size() << " "
         << _model->getLayer(_model->getLayerCount() - 1)
                .getDots()
                .size()
         << " ";

    for (int i = 0; i < _model->getLayerCount(); i++) {
        if (_model->getLayer(i).getType() == LayerType::INPUT) {
            continue;
        }

        for (int j = 0; j < _model->getLayer(i).getDots().size(); j++) {
            for (int k = 0; k < _model->getLayer(i - 1).getDots().size();
                 k++) {
                file << _model->getLayer(i).getWeight(j, k) << " ";
            }
        }
    }

    file.close();
    return 0;
}

int AiModel::run_model(vector<double> &input) {
    return _model->run_model(input);
}

int AiModel::getPrediction(vector<double> &input) {
    int max1 = 0, max = 0;
    for (int i = 0; i < 9; i++) {
        if (_model->getOutput()[max1] < _model->getOutput()[i]) {
            max1 = i;
        }
    }

    if (input[max1] != 0.5) {
        cout << "error 1: " << _model->getOutput()[max1] << endl;
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

AiModel::~AiModel() { delete _model; }
