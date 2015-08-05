#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "OpRoot.h"

using namespace std;

/*Get the current value from the calculator and a list of parameters and performs the Power operation with the first parameters.
May Throw Invalid_Arguments if the first parameter in NaN, prints a message to the user and return the original value */
double OpRoot::CalcResult(double currVal, const vector<string>& parameters) const
{
	try
	{
		return pow(currVal, 1.0 / stod(parameters[0]));
	}
	catch (...)
	{
		cout << "One or more parameters are not a number.\n";
		return currVal;
	}
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpRoot::About()
{
	string about = "Root\nSets the current value to its Nth root (N=Parameter). \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "\nMin. required parameters: " + to_string(RequiredParameters()) + ".\nMax. parameters: 1";
	return about;
}