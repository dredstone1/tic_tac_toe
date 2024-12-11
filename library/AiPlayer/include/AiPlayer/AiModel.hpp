#ifndef AIMODEL_HPP
#define AIMODEL_HPP

#include "../src/model.hpp"
#include <string>

class AiModel {
  private:
    model *_model;

  public:
    AiModel();
    AiModel(string file_name);
    int load(string file_name);
    int save(string file_name);
    int run_model(vector<double> &input);
    int getPrediction(vector<double> &input);
    ~AiModel();
};

#endif // AIMODEL_HPP
