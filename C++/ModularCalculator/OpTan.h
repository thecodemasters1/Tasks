#pragma once
#include <string>
#include <vector>
#include "CalculatorOperation.h"

using namespace std;

//derived CalculatorOperation Tangent: Operate the Tangent function on the current value.
class OpTan : public CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation (use base abstractt c'tor).
	OpTan(const vector<string>& operations) : CalculatorOperation(operations) {}
	//D'tor
	virtual ~OpTan() {}
	//Return the number of parameters required for the operation.
	virtual int RequiredParameters() const { return 0; }
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About();
	//Get the current value from the calculator and performs the Tangent operation.
	virtual double CalcResult(double currVal, const vector<string>& parameters) const;
};