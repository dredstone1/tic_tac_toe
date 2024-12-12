#ifndef BACKPROPAGATION
#define BACKPROPAGATION

#include "AiPlayer/AiModel.hpp"
#include "database/dataBase.hpp"

class BackPropagation {
  private:
    TrainBoard &train_board;
    AiModel &model;
    double learning_rate;
    vector<vector<double>> delta_weights;
    vector<double> cost_derivative(vector<double> &output,
                                   vector<double> &target);

  public:
    BackPropagation(AiModel &model, double learning_rate,
                    TrainBoard &train_board);
    void run_back_propagation();
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
