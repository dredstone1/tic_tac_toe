#ifndef BACKPROPAGATION
#define BACKPROPAGATION

#include "AiPlayer/AiModel.hpp"
#include "database/dataBase.hpp"
#include "gradient.hpp"

class BackPropagation {
  private:
    AiModel &model;
    double learning_rate;
    void run_back_propagation(TrainBoard &boards);
    double get_total_error(TrainBoard &target);
    static double get_error(double prediction, double target);
    void calculate_pattern_gradients(TrainBoard &targer, gradient &gradients);
    void update_weights(int bash_size, gradient &gradients);

  public:
    BackPropagation(AiModel &model, double learning_rate);
    double run_back_propagation(vector<TrainBoard> &boards);
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
