#if !defined SAFEARRAY_H_
#define SAFEARRAY_H_

#include "OutOfRangeException.h"

/*Template class representing a safe array, make sure you stay in the array boundaries.
Will throw OutOfRangeExcception in case of boundaries violation.*/
template<class T>
class SafeArray
{
public:
	//C'tor, Get length, Allocating memory for the array in the required size and type and store length in a member.
	SafeArray(int length) : arr(new T[length]), Length(length) {}
	//D'tor, free the array memory.
	~SafeArray() { delete[] arr; }
	//Return the length of the Safe array.
	int getLength() const { return Length; }

	/*Overload operator[], Return a reference to the member in the index place in the array
	Will throw OutOfRangeException on boundaries violation */
	T& operator[] (int index) const;
	/*Overload operator+, Return a pointer to the member in the n place in the array
	Will throw OutOfRangeException on boundaries violation */
	T* operator+ (int n) const;
	/*Overload operator+, Return a pointer to the member in the -n place in the array
	Will throw OutOfRangeException on boundaries violation */
	T* operator- (int n) const;
	/*Overload operator-, Return the Difference between the start pointer (arr[0]) and the passed pointer
	Difference is in number of Type size. (not number of bytes) */
	int operator- (const T* p) const;

	//Overload operator*, Return a reference to the first position in the array;
	T& operator* ();
	//Overload operator&, Return a pointer to the first position in the array;
	T* operator& ();

private:
	//The private T array, managed by the class. 
	T * arr;
	//The length of the T array.
	int Length;
};


/*Overload operator[], Return a reference to the member in the index place in the array
Will throw OutOfRangeException on boundaries violation */
template <class T>
T& SafeArray<T>::operator[] (int index) const
{
	try
	{
		if (index < 0 || index >= Length)
		{
			throw OutOfRangeException(Length, index);
		}
		return arr[index];
	}
	catch (OutOfRangeException ex)
	{
		ex.Print();
		throw;
	}
}

/*Overload operator+, Return a pointer to the member in the n place in the array
Will throw OutOfRangeException on boundaries violation */
template <class T>
T* SafeArray<T>::operator+ (int n) const
{
	try
	{
		if (n < 0 || n >= Length)
			throw OutOfRangeException(Length, n);
		return arr + n;
	}
	catch (OutOfRangeException ex)
	{
		ex.Print();
		throw;
	}
}

/*Overload operator+, Return a pointer to the member in the -n place in the array
Will throw OutOfRangeException on boundaries violation */
template <class T>
T* SafeArray<T>::operator- (int n) const
{
	try
	{
		if (n <= -Length || n > 0)
			throw OutOfRangeException(Length, n);
		return arr - n;
	}
	catch (OutOfRangeException ex)
	{
		ex.Print();
		throw;
	}
}

/*Overload operator-, Return the Difference between the start pointer (arr[0]) and the passed pointer
Difference is in number of Type size. (not number of bytes) */
template <class T>
int SafeArray<T>::operator- (const T* p) const
{
	return arr - p;
}

//Overload operator*, Return a reference to the first position in the array;
template <class T>
T& SafeArray<T>::operator* ()
{
	return *arr;
}

//Overload operator&, Return a pointer to the first position in the array;
template <class T>
T* SafeArray<T>::operator& ()
{
	return arr;
}

#endif