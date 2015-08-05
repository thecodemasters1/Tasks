#if !defined REDWINE_H_
#define REDWINE_H_
#include "Wine.h"

using namespace std;

class RedWine : public Wine
{
public:
	//C'tor - get a string with the name of the red wine and its year. Set the name and year with the passed values.
	RedWine(string name, int year);
	//D'tor
	~RedWine() {};
	//Prints a message to the user with the name of the red wine + year and how to prepare it.
	virtual void prepare();
};

#endif