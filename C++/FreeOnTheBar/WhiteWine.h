#if !defined WHITEWINE_H_
#define WHITEWINE_H_
#include "Wine.h"

using namespace std;

class WhiteWine : public Wine
{
public:
	//C'tor - get a string with the name of the white wine and its year. Set the name and year with the passed values.
	WhiteWine(string name, int year);
	//D'tor
	~WhiteWine() {};
	//Prints a message to the user with the name of the white wine + year and how to prepare it.
	virtual void prepare();
};

#endif