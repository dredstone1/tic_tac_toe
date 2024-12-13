#ifndef BACKPROPAGATION
#define BACKPROPAGATION

#include "AiPlayer/AiModel.hpp"
#include "database/dataBase.hpp"

class BackPropagation {
  private:
    AiModel &model;
    double learning_rate;
    Gradient gradients;
    void resetGradients();

  public:
    BackPropagation(AiModel &model, double learning_rate);
    void run_back_propagation(vector<TrainBoard> &boards);
    void update_weights(int bash_size);
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
