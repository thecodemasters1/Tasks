#include <iostream>
#include <string>
#include  <vector>
#include "OpDivide.h"

using namespace std;

/*Get the current value from the calculator and a list of parameters and performs the Division operation with the parameters.
May Throw: 
Invalid_Arguments if one or more parameter in NaN, prints a message to the user and return the original value
0 if one of the parameters is zero and there is an attempt to divide by zero*/
double OpDivide::CalcResult(double currVal, const vector<string>& parameters) const
{
	try
	{
		double newVal = currVal;
		for (auto param : parameters)
		{
			double d_param = stod(param);
			if (d_param == 0)
			{
				throw 0;
			}
			newVal /= d_param;
		}
		return newVal;
	}
	catch (int n)
	{
		cout << "Attempted to divide by zero.\n";
		return currVal;
	}
	catch (...)
	{
		cout << "One or more parameters are not a number.\n";
		return currVal;
	}
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpDivide::About()
{
	string about = "Division\nDivides the current value by the parameters, one after one. \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "\nMin. required parameters: " + to_string(RequiredParameters()) + ".\nMax. parameters: inf";
	return about;
}