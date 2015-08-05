#include <iostream>
#include <string>
#include <vector>
#include "OpSet.h"

using namespace std;

/*Get the current value from the calculator and a list of parameters and performs the Set operation with the first parameters.
May Throw Invalid_Arguments if the first parameter in NaN, prints a message to the user and return the original value */
double OpSet::CalcResult(double currVal, const vector<string>& parameters) const
{
	try
	{
		return stod(parameters[0]);
	}
	catch (...)
	{
		cout << "One or more parameters are not a number.\n";
		return currVal;
	}
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpSet::About()
{
	string about = "Set\nSets the current value to the parameter's value. \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "\nMin. required parameters: " + to_string(RequiredParameters()) + ".\nMax. required parameters: 1";
	return about;
}