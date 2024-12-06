#ifndef RELU_H
#define RELU_H

#include "ActivationFunction.h"

class ReLU : public ActivationFunction {
public:
    double compute(double x) const override;
    std::string name() const override;
};

#endif // RELU_H
