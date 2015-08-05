#include <iostream>
#include <string>
#include "WhiteWine.h"

using namespace std;

//C'tor - get a string with the name of the white wine and its year. Set the name and year with the passed values.
WhiteWine::WhiteWine(string name, int year)
{
	Name = name;
	Year = year;
}

//Prints a message to the user with the name of the white wine + year and how to prepare it.
void WhiteWine::prepare()
{
	cout << "You ordered " << getName() << ".\nTo prepare it you need to cool it and then serve.\n";
}