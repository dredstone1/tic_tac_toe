#ifndef AIMODEL_HPP
#define AIMODEL_HPP

#include "../src/model.hpp"

class AiModel {
    private:
        model *_model = nullptr;

  public:
    AiModel();
    int load();
    int basic_setup();
    int run_model(vector<double> &input);
    int getPrediction(vector<double> &input);
    ~AiModel();
};

#endif // AIMODEL_HPP
