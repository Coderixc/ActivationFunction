#ifndef MASTER_ACTIVATION_FUNCTION_H
#define MASTER_ACTIVATION_FUNCTION_H

#include "ActivationFunction.h"


class LeakyReLU : public ActivationFunction {

public:
	double compute(double x) const override;
	double compute(double x, double alpha)  ;
	std::string name() const override;

	void setalpha(double x) ;

private:
	double alpha = 0.1;

};



#endif //MASTER_ACTIVATION_FUNCTION_H
