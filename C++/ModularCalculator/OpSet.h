#pragma once
#include <string>
#include <vector>
#include "CalculatorOperation.h"

//derived CalculatorOperation Set: Set the current value to the parameter value.
class OpSet : public CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation (use base abstractt c'tor).
	OpSet(const vector<string>& operations) : CalculatorOperation(operations) {}
	//D'tor
	virtual ~OpSet() {}
	//Return the number of parameters required for the operation.
	virtual int RequiredParameters() const { return 1; }
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About();
	/*Get the current value from the calculator and a list of parameters and performs the Set operation with the first parameters.
	May Throw Invalid_Arguments if the first parameter in NaN, prints a message to the user and return the original value */
	virtual double CalcResult(double currVal, const vector<string>& parameters) const;
};