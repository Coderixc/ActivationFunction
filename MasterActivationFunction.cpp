
#include "MasterActivationFunction.h"




#pragma region Section:LeakyReLU Activation Function Body

double LeakyReLU::compute(double x) const
{
	return  (x >= 0) ? x : LeakyReLU::alpha * x;;
}

double LeakyReLU::compute(double x, double alpha_parameter) 
{
	LeakyReLU::alpha = alpha_parameter;
	return LeakyReLU::compute(x);
}

void LeakyReLU::setalpha(double alpha_parameter)
{
	LeakyReLU::alpha = alpha_parameter;
}

std::string LeakyReLU::name() const
{
	return "LeakyReLU";
}
#pragma endregion



