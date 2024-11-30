#ifndef ACTIVATIONFUNCTIONS_HPP
#define ACTIVATIONFUNCTIONS_HPP

#include <cmath>
#include <vector>

using namespace std;

namespace ActivationFunctions {
void softmax(vector<double> &metrix);
void relu(vector<double> &metrix);
void none(vector<double> &metrix);
} // namespace ActivationFunctions

#endif // ACTIVATIONFUNCTIONS_HPP
