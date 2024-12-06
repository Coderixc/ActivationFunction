#include "Sigmoid.h"
#include <cmath>

double Sigmoid::compute(double x) const 
{
    auto result =  1.0 / (1.0 + std::exp(-x));
    return result;
}

std::string Sigmoid::name() const {
    return "Sigmoid";
}
