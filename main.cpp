#include "ActivationFuncFactory.h"
#include "Sigmoid.h"
#include "ReLU.h"
#include "Tanh.h"
#include <iostream>

// Register activation functions
void registerActivationFunctions() {
    auto& factory = ActivationFunctionFactory::getInstance();
    factory.registerFunction("Sigmoid", []() { return std::make_unique<Sigmoid>(); });
    factory.registerFunction("ReLU", []() { return std::make_unique<ReLU>(); });
    factory.registerFunction("Tanh", []() { return std::make_unique<Tanh>(); });
}

int main() {
    registerActivationFunctions();

    auto& factory = ActivationFunctionFactory::getInstance();

    try {
        auto sigmoid = factory.create("Sigmoid");
        auto relu = factory.create("ReLU");

        double input = -1.5;
        std::cout << sigmoid->name() << " activation: " << sigmoid->compute(input) << '\n';
        std::cout << relu->name() << " activation: " << relu->compute(input) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
