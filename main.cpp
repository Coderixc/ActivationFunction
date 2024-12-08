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

}

int main() {
    registerActivationFunctions();

    auto& factory = ActivationFunctionFactory::getInstance();

    try {
        auto sigmoid = factory.create("Sigmoid");
        auto relu = factory.create("ReLU");



        double input = -100;
        std::cout << sigmoid->name() << " activation: " << sigmoid->compute(input) << '\n';
        std::cout << relu->name() << " activation: " << relu->compute(input) << '\n';

        LeakyReLU* leakyRelu = new LeakyReLU();
        leakyRelu->setalpha(0.1);

        std::cout << leakyRelu->name() << " activation: " << leakyRelu->compute(input) << '\n';
        delete leakyRelu;

        Swish* swishaf = new Swish();
        swishaf->setbeta(2);

        std::cout << swishaf->name() << " activation: " << swishaf->compute(input) << '\n';
        delete swishaf;


    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


#pragma region Question
/*
What is the use of "->" Operator ?
 -- access members of an object through a pointer. 
 -- shorthand for dereferencing a pointer 
 -- When you have a pointer to an object, 
 -- you cannot directly use the . operator to access its members. 
*/

#pragma endregion
