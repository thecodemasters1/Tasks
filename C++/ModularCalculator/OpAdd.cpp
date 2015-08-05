#include <iostream>
#include <string>
#include <vector>
#include "OpAdd.h"

using namespace std;

/*Get the current value from the calculator and a list of parameters and performs the Addition operation with the parameters.
May Throw Invalid_Arguments if one or more parameter in NaN, prints a message to the user and return the original value */
double OpAdd::CalcResult(double currVal, const vector<string>& parameters) const
{
	try
	{
		double newVal = currVal;
		for (auto param : parameters)
		{
			newVal +=  stod(param);
		}
		return newVal;
	}
	catch (...)
	{
		cout << "One or more parameters are not a number.\n";
		return currVal;
	}
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpAdd::About()
{
	string about = "Addition\nAdds the parameters to the current value. \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "\nMin. required parameters: " + to_string(RequiredParameters()) + ".\nMax. parameters: inf";
	return about;
}