#if !defined DRINK_H_
#define DRINK_H_

using namespace std;

/*Base abstract class of a Drink, all other classes derives from this class. With a name parameter for a drink */
class Drink
{
public:
	//Inline virtual base function, return the name of the drink, may be overrided by the derived classes.
	virtual string getName() { return Name; }
	//Pure virtual function, will be implemented in a way that prints a message with the drink name and how to prepare it.
	virtual void prepare() = 0;
protected:
	//The name of the drink is stored here.
	string Name;
};

#endif