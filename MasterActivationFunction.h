#ifndef MASTER_ACTIVATION_FUNCTION_H
#define MASTER_ACTIVATION_FUNCTION_H

#include "ActivationFunction.h"
#include <vector>

class LeakyReLU : public ActivationFunction {

public:
	double compute(double x) const override;
	double compute(double x, double alpha)  ;
	std::string name() const override;

	void setalpha(double x) ;

private:
	double alpha = 0.1;

};


class Swish : public ActivationFunction 
{
public :
	double compute(double x) const override;
	double compute(double x,double beta_parameter );
	std::string name() const override;

	void setbeta(double betaParameter);

private : 
	double beta = 1.0;


};

class Softplus : public ActivationFunction
{
public:
	double compute(const double x) const override;
	std::string name() const override;

};

class  Maxout : public ActivationFunction
{
private :
	std::vector<double> coefficients;

public :
	double compute(double x) const override;

	explicit Maxout(const std::vector<double>& coeffs);

	std::string name() const override;
};



#endif //MASTER_ACTIVATION_FUNCTION_H
