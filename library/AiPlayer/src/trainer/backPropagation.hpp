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
    void run_back_propagation(TrainBoard &boards);
    double get_error(TrainBoard &target);

  public:
    BackPropagation(AiModel &model, double learning_rate);
    void run_back_propagation(vector<TrainBoard> &boards);
    void update_weights(int bash_size);
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
