#pragma once
#include <string>
#include <vector>
#include "CalculatorOperation.h"

using namespace std;

//derived CalculatorOperation Cosine: Operate the cosine function on the current value (degrees)
class OpCos : public CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation (use base abstractt c'tor).
	OpCos(const vector<string>& operations) : CalculatorOperation(operations) {}
	//D'tor
	virtual ~OpCos() {}
	//Return the number of parameters required for the operation.
	virtual int RequiredParameters() const { return 0; }
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About();
	//Get the current value from the calculator and performs the Cosine operation.
	virtual double CalcResult(double currVal, const vector<string>& parameters) const;
};