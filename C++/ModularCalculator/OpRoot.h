#pragma once
#include <string>
#include <vector>
#include "CalculatorOperation.h"

//derived CalculatorOperation Root: return the Nth root of the current value (N=Parameter)
class OpRoot : public CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation (use base abstractt c'tor).
	OpRoot(const vector<string>& operations) : CalculatorOperation(operations) {}
	//D'tor
	virtual ~OpRoot() {}
	//Return the number of parameters required for the operation.
	virtual int RequiredParameters() const { return 1; }
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About();
	/*Get the current value from the calculator and a list of parameters and performs the Root operation with the first parameters.
	May Throw Invalid_Arguments if the first parameter in NaN, prints a message to the user and return the original value */
	virtual double CalcResult(double currVal, const vector<string>& parameters) const;
};