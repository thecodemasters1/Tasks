#if !defined WINE_H_
#define WINE_H_
#include <string>
#include "Drink.h"

/*Derived abstract class of abstract class Drink, defines the basic common new member of wines - year 
and the new getName function, with both the name and year of the wine */
class Wine : public Drink
{
public:
	// T: put here ctor
	//Inline virtual base function, return the name of the drink + year;
	virtual string getName() { return Name + "(Year " + to_string(Year) + ")"; }
protected:
	//The wine's year is stored in here.
	int Year;
};

#endif
