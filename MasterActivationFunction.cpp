
#include "MasterActivationFunction.h"
#include "Sigmoid.h"
#include "cmath"
#include <stdexcept>

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

#pragma region Section:Swish Activation Function Body

double Swish::compute(double x) const
{
	Sigmoid* sigmoid = new Sigmoid();
	double sigm =  sigmoid->compute(x);
	delete sigmoid;
	return x * sigm;
}

double Swish::compute(double x , double beta_parameter) 
{
	Swish::beta = beta_parameter;
	Sigmoid* sigmoid = new Sigmoid();
	double sigm = sigmoid->compute(Swish::beta * x);
	delete sigmoid;
	return sigm;
}

void Swish::setbeta(double beta_parameter)
{
	Swish::beta = beta_parameter;
}
std::string Swish::name() const
{
	return "Swish";
}

#pragma endregion

#pragma region Section : SoftPlus Activation Function body
double Softplus::compute(double x) const
{
	return std::log(1 + std::exp(x));
}

std::string Softplus::name() const
{
	return "Softplus";
}

#pragma endregion

#pragma region Section : Maxout Activation Function body
Maxout::Maxout(const std::vector<double>& coeffs) : coefficients(coeffs) {
	if (coefficients.empty())
	{
		throw std::invalid_argument("Coefficients for Maxout cannot be empty!");
	}
}

double Maxout::compute(double x) const
{
	double maxvalue = coefficients[0] * x;
	for (size_t i = 1; i < coefficients.size(); i++)
	{
		maxvalue = std::max(maxvalue, coefficients[i] * x);
	}
	return maxvalue;
}
std::string Maxout::name() const
{
	return "Maxout";
}

#pragma endregion