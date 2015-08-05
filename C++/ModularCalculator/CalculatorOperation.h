#pragma once
#include <string>
#include <vector>

using namespace std;

//Abstract class of an operation in the calculator, used as base class for the operations.
class CalculatorOperation
{
public:
	//C'tor, Get vector with keywords of the operation Set supported keywords for the operation.
	inline CalculatorOperation(const vector<string>& operations);
	//D'tor
	virtual ~CalculatorOperation() {}
	//Get a keyword and return true if the operation supports the keyword, otherwise return false.
	inline virtual bool SupportsOperation(string op_string) const;
	//Add a keyword to the supported keyword of the operation
	inline void AddOperation(string op_stirng) { SupportedOperations.push_back(op_stirng); }
	//Return the number of parameters required to for the operation.
	virtual int RequiredParameters() const = 0;
	//Return a string with a brief description about the operation, its keywords and parameters.
	virtual string About() = 0;
	//Get the current value from the calculator and a list of parameters and preform the operation on the current value.
	virtual double CalcResult(double currVal, const vector<string>& parameters) const = 0;
protected:
	//a vector to be filled with the operation's keywords
	vector<string> SupportedOperations;
};

//C'tor, Get vector with keywords of the operation Set supported keywords for the operation.
inline CalculatorOperation::CalculatorOperation(const vector<string>& operations)
{
	for (auto op : operations)
	{
		SupportedOperations.push_back(op);
	}
}

//Get a keyword and return true if the operation supports the keyword, otherwise return false.
inline bool CalculatorOperation::SupportsOperation(string op_string) const
{
	for (auto op : SupportedOperations)
	{
		if (op == op_string)
		{
			return true;
		}
	}
	return false;
}