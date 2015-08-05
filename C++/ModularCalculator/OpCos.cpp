#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "OpCos.h"
#include "modcalclib.h"

using namespace std;

//Get the current value from the calculator and performs the Cosine operation.
double OpCos::CalcResult(double currVal, const vector<string>& parameters) const
{
	if (((int)currVal - 90) % 180 == 0)
	{
		return 0;
	}
	return cos(currVal*PI / 180);
}

//Return a string with a brief description about the operation, its keywords and parameters.
string OpCos::About()
{
	string about = "Cosine\nReturn the cosine of the current value (Degrees). \nOperation keywords: ";
	for (auto op : SupportedOperations)
		about += op + " ";
	about += "No parameters required.";
	return about;
}