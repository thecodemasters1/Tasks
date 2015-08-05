#include <iostream>
#include "OutOfRangeException.h"

using namespace std;

//Print a message with details about the exception thrown.
void OutOfRangeException::Print()
{
	if (AttemptedIndex < 0)
		cout << "OutOfRangeException occurred: Attempted to access cell: " << AttemptedIndex << " while start index is 0.";
	else
		cout << "OutOfRangeException occurred: Attempted to access cell: " << AttemptedIndex << " while last index is " << SafeArrayLength-1 << ".";
}