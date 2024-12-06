#ifndef TANH_H
#define TANH_H

#include "ActivationFunction.h"

class Tanh : public ActivationFunction {
public:
    double compute(double x) const override;
    std::string name() const override;
};

#endif // TANH_H
