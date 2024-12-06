
#ifndef SIGMOID_H
#define SIGMOID_H

#include "ActivationFunction.h"

class Sigmoid : public ActivationFunction 
{
public:
    double compute(double x) const override;
    std::string name() const override;
};

#endif // SIGMOID_H
