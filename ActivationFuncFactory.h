#ifndef ACTIVATION_FUNCTION_FACTORY_H
#define ACTIVATION_FUNCTION_FACTORY_H

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include "ActivationFunction.h"

class ActivationFunctionFactory {
public:
    using Creator = std::function<std::unique_ptr<ActivationFunction>()>;  //interface for creating objects,

    static ActivationFunctionFactory& getInstance();

    void registerFunction(const std::string& name, Creator creator); //allows subclasses or client code to decide which class to instantiate.
    std::unique_ptr<ActivationFunction> create(const std::string& name) const;

private:
    std::unordered_map<std::string, Creator> creators;
};

#endif // ACTIVATION_FUNCTION_FACTORY_H