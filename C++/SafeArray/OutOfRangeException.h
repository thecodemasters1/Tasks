#if !defined OUTOFRANGEEXCEPTION_H_
#define OUTOFRANGEEXCEPTION_H_

/*Class representing an exception "Out of Range", with data about the access violation, 
thrown in case of Safe array's boundaries violation.*/
class OutOfRangeException
{
public:
	//C'tor, Get the safe array length and index attemped to access and set them in the class object.
	OutOfRangeException(int length, int index) : SafeArrayLength(length), AttemptedIndex(index) {}
	//D'tor
	~OutOfRangeException() {};
	//Print a message with details about the exception thrown.
	void Print();

private:
	//Store the length of the safe array in which the exception occured
	int SafeArrayLength;
	//Store the index attempted to access when causing the violation.
	int AttemptedIndex;
};

#endif