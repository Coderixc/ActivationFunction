#include "ReLU.h"
#include <algorithm>

double ReLU::compute(double x) const {
     /**
     * @brief Rectified Linear Unit (ReLU) Activation Function.
     *
     * ReLU is defined as:
     *    f(x) = max(0, x)
     *
     * Mathematical Representation:
     *    f(x) = { x, if x > 0
     *           { 0, if x <= 0
     *
     * Derivative:
     *    f'(x) = { 1, if x > 0
     *            { 0, if x <= 0
     *
     * Properties:
     * - Introduces non-linearity to the model.
     * - Sparsity: Outputs 0 for x <= 0, turning off certain neurons.
     *
     * Usage:
     * This function is commonly used as an activation function in neural networks.
     */


    return std::max(0.0, x);
}

std::string ReLU::name() const {
    return "ReLU";
}
