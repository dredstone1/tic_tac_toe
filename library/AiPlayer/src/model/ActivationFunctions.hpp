#ifndef ACTIVATIONFUNCTIONS_HPP
#define ACTIVATIONFUNCTIONS_HPP

#include <cmath>
#include <vector>

using namespace std;

namespace ActivationFunctions {
enum ActivationFunctionType {
    SOFTMAX,
    RELU,
    NONE,
};

class ActivationFunction {
  private:
    ActivationFunctionType type;
    static void softmax(vector<double> &metrix);
    static void relu(vector<double> &metrix);
    static void none(vector<double> &metrix);
    static double max_vector(vector<double> &metrix);
      

  public:
    ActivationFunction(ActivationFunctionType type_);
    ~ActivationFunction() = default;
    void activate(vector<double> &metrix);
    ActivationFunctionType getType() { return this->type; };
};
}; // namespace ActivationFunctions

#endif // ACTIVATIONFUNCTIONS_HPP
