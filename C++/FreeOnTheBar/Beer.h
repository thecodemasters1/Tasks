#if !defined BEER_H_
#define BEER_H_
#include "Drink.h"

//Derived class of base Drink, Define a Beer;
class Beer : public Drink
{
public:
	//C'tor - get a string with the name of the beer and set the name to it.
	Beer(string name);
	//D'tor
	~Beer() {};
	//Prints a message to the user with the name of the drink and how to prepare it.
	virtual void prepare();
};

#endif
