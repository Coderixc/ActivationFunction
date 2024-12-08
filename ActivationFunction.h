#ifndef ACTIVATION_FUNCTION_H
#define ACTIVATION_FUNCTION_H

#include <string>

class ActivationFunction {
public:
    virtual double compute(double x) const = 0;  // Compute activation
    virtual std::string name() const = 0;        // Return function name
    virtual ~ActivationFunction() = default;    // Ensure proper cleanup
    
};

#endif // ACTIVATION_FUNCTION_H

/* Learning
#ifndef :Common Pattern known as include guard. It will
first check this particular symbol or Macros ALready Defined,
Then it wil not Proceed the below code

#Why virtual before memebr Func of class ?
-- Enable Polymorphism
-- Behaviour (or Body of fucntion) van be changed in Derived class

#Whay Const as memebr function ?
-- Function will not modify the state of the class , meaning it has no right to Update/modify member variables.

# Whay Funtion is passed with = 0?
-- This is Pure Virtual function
-- A class with one Pure Virtual Function is called as ABstract Class
-- Abstract classes - Cannot be instantiated own their own

#Can we use  other values excpet 0 "= 0" to define Pure virtual function ?
-- No , Language " = 0" is special role to marke the fucntion as pure virtual function
--  My marking with "= 0", this act as a Contract( Interface) , The class which inherit ,
must implement this function
*/