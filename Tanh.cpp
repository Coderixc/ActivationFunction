#include "Tanh.h"
#include <cmath>

double Tanh::compute(double x) const {
    return std::tanh(x);
}

std::string Tanh::name() const {
    return "Tanh";
}
