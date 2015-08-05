#include <iostream>
#include <string>
#include "Beer.h"

using namespace std;

//C'tor - get a string with the name of the beer and set the name to it.
Beer::Beer(string name)
{
	Name = name;
}

//Prints a message to the user with the name of the drink and how to prepare it.
void Beer::prepare()
{
	cout << "Your ordered " << Name << ".\nAll you need to do is pour it into a glass.\n";
}