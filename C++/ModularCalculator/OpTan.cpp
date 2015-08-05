#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "OpTan.h"
#include "modcalclib.h"

using namespace std;

//Get the current value from the calculator and performs the Tangent operation.
double OpTan::CalcResult(double currVal, const vector<string>& parameters) const
{
	try
	{
		if (((int)currVal - 90) % 180 == 0)
		{
			throw 0;
		}
		return tan(currVal*PI / 180);
	}
	catch (int n)
	{
		cout << "Tngent is not defined for 90+180K (Degrees).\n";
		return currVal;
	}
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpTan::About()
{
	string about = "Tangent\nReturn the tangent of the current value (Degrees). \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "No parameters required.";
	return about;
}