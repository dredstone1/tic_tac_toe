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
    static vector<double> calculate_delta(vector<double> &target, vector<double> &derivatives);
    double get_total_error(TrainBoard &target);
    static double get_error(double prediction, double target);
    void calculate_pattern_gradients(TrainBoard &targer, gradient &gradients);
    void update_weights(int bash_size, gradient &gradients);
    static vector<double> calculate_target(Layer &layer, Layer &next_layer, vector<double> &next_delta, vector<double> &target);
    static vector<double> calculate_derivative(Layer &layer);
    static gradient_layer calculate_gradient(Layer &layer, vector<double> &deltas);
    static void check_for_nan(const vector<double> &values, const string &label);
    static void clip_gradients(gradient_layer &gradients, double clip_value);

  public:
    BackPropagation(AiModel &model, double learning_rate);
    double run_back_propagation(vector<TrainBoard> &boards);
    ~BackPropagation() = default;
};

#endif // BACKPROPAGATION
