#pragma once
#include <string>
#include <vector>
#include "CalculatorOperation.h"

using namespace std;

//derived CalculatorOperation Division: Divide the numbers from the current value
class OpDivide : public CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation (use base abstractt c'tor).
	OpDivide(const vector<string>& operations) : CalculatorOperation(operations) {}
	//D'tor
	virtual ~OpDivide() { SupportedOperations.clear(); }
	//Return the number of parameters required for the operation.
	virtual int RequiredParameters() const { return 1; }
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About();
	/*Get the current value from the calculator and a list of parameters and performs the Division operation with the parameters.
	May Throw:
	Invalid_Arguments if one or more parameter in NaN, prints a message to the user and return the original value
	0 if one of the parameters is zero and there is an attempt to divide by zero*/
	virtual double CalcResult(double currVal, const vector<string>& parameters) const;
};