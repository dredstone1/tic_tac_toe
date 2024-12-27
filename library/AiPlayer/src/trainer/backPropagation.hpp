#ifndef BACKPROPAGATION
#define BACKPROPAGATION

#include "AiPlayer/AiModel.hpp"
#include "database/dataBase.hpp"
#include "gradient.hpp"

#define CLIP_GRADIENTS 0.5

class BackPropagation {
  private:
    AiModel &model;
    double learning_rate;
    gradient gradients;
    static vector<double> calculate_delta(vector<double> &target, vector<double> &derivatives);
    static double get_total_error(TrainBoard &target, neural_network &temp_network);
    static double get_cross_entropy_loss(vector<double> prediction, vector<double> &target);
    static void calculate_pattern_gradients(TrainBoard &targer, gradient &gradients, neural_network &temp_network);
    void update_weights(int bash_size, gradient &gradients);
    static vector<double> calculate_target(Layer &layer, Layer &next_layer, vector<double> &next_delta, vector<double> &target);
    static vector<double> calculate_derivative(Layer &layer);
    static gradient_layer calculate_gradient(Layer &layer, vector<double> &deltas);
    static void check_for_nan(const vector<double> &values);
    static void clip_gradients(gradient_layer &gradients, double clip_value);
    double run_back_propagation(TrainBoard &board, gradient &gradients);

  public:
    BackPropagation(AiModel &_model, double _learning_rate);
    double run_back_propagation(vector<TrainBoard> &boards);
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
