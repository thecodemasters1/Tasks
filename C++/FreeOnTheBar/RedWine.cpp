#include <iostream>
#include <string>
#include "RedWine.h"

using namespace std;

//C'tor - get a string with the name of the red wine and its year. Set the name and year with the passed values.
RedWine::RedWine(string name, int year)
{
	Name = name;
	Year = year;
}

//Prints a message to the user with the name of the red wine + year and how to prepare it.
void RedWine::prepare()
{
	cout << "You ordered " << getName() << ".\nTo prepare it you need to serve it in the room temperature (16C-18C).\n";
}