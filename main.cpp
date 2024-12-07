#include "ActivationFuncFactory.h"
#include "Sigmoid.h"
#include "ReLU.h"
#include "Tanh.h"
#include <iostream>
#include "MasterActivationFunction.h"

// Register activation functions
void registerActivationFunctions() {
    auto& factory = ActivationFunctionFactory::getInstance();
    factory.registerFunction("Sigmoid", []() { return std::make_unique<Sigmoid>(); });
    factory.registerFunction("ReLU", []() { return std::make_unique<ReLU>(); });
    factory.registerFunction("Tanh", []() { return std::make_unique<Tanh>(); });
    factory.registerFunction("LeakyReLU", []() { return std::make_unique<LeakyReLU>(); });
}

int main() {
    registerActivationFunctions();

    auto& factory = ActivationFunctionFactory::getInstance();

    try {
        auto sigmoid = factory.create("Sigmoid");
        auto relu = factory.create("ReLU");

        auto leakyrelu = factory.create("LeakyReLU");

        double input = -100;
        std::cout << sigmoid->name() << " activation: " << sigmoid->compute(input) << '\n';
        std::cout << relu->name() << " activation: " << relu->compute(input) << '\n';

 

        std::cout << leakyrelu->name() << " activation: " << leakyrelu->compute(input,1.1) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
