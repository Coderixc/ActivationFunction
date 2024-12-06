#include "ActivationFuncFactory.h"
#include <stdexcept>

ActivationFunctionFactory& ActivationFunctionFactory::getInstance() {
    static ActivationFunctionFactory instance;
    return instance;
}

void ActivationFunctionFactory::registerFunction(const std::string& name, Creator creator) {
    creators[name] = creator;
}

std::unique_ptr<ActivationFunction> ActivationFunctionFactory::create(const std::string& name) const {
    auto it = creators.find(name);
    if (it != creators.end()) {
        return it->second();
    }
    throw std::runtime_error("Activation function not found: " + name);
}
