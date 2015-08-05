#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "OpSin.h"
#include "modcalclib.h"

using namespace std;

//Get the current value from the calculator and performs the Sine operation.
double OpSin::CalcResult(double currVal, const vector<string>& parameters) const
{
	return sin(currVal*PI / 180);
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpSin::About()
{
	string about = "Sine\nReturn the sine of the current value (Degrees). \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "No parameters required.";
	return about;
}