#include <iostream>
#include <cmath>
#include "Fraction.h"

using namespace std;

//Return the numerator
int Fraction::getNumerator() const
{
	return Numerator;
}

//Get a number and Set the numerator
void Fraction::setNumerator(int numerator)
{
	Numerator = numerator;
}

//Get the denominator
int Fraction::getDenominator() const
{
	return Denominator;
}

//Get a number and Set the denominator
void Fraction::setDenominator(int denominator)
{
	Denominator = denominator; // T: check denominator is not 0, hanndle negative num
}

//Reduce the fraction to the smallest value possible.
void Fraction::Reduce()
{
	int gcd = 1;
	if (abs(Numerator) < abs(Denominator))
	{
		gcd = getGreatestCommonDivisor(abs(Denominator), abs(Numerator));
	}
	else
	{
		gcd = getGreatestCommonDivisor(abs(Numerator), abs(Denominator));
	}
	Numerator /= gcd;
	Denominator /= gcd;
}

//private function, get 2 numbers and return their greatest common divisor (used or reduce function).
int Fraction::getGreatestCommonDivisor(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return getGreatestCommonDivisor(b, a%b);
}

//Prints the fraction.
void Fraction::print() const
{
	if (Denominator == 1)
	{
		cout << Numerator;
	}
	else
	{
		cout << Numerator << "/" << Denominator;
	}
}

//Overload operator +, add 2 fractions;
Fraction Fraction::operator+ (const Fraction& f2) const
{
	return Fraction((Numerator*f2.getDenominator() + f2.getNumerator()*Denominator),
		(Denominator * f2.getDenominator()));
}

//Overload operator +, add a fraction and an int;
Fraction Fraction::operator+ (int f2) const
{
	return Fraction((Numerator + f2*Denominator),
		(Denominator));
}

//Overload operator -, subtract 2 fractions;
Fraction Fraction::operator- (const Fraction& f2) const
{
	return Fraction((Numerator*f2.getDenominator() - f2.getNumerator()*Denominator),
		(Denominator * f2.getDenominator()));
}

//Overload operator -, subtract a fraction and an int;
Fraction Fraction::operator- (int f2) const
{
	return Fraction((Numerator - f2*Denominator),
		(Denominator));
}

//Overload operator *, Multiplies 2 fractions;
Fraction Fraction::operator* (const Fraction& f2) const
{
	return Fraction(Numerator * f2.getNumerator(), Denominator * f2.getDenominator());
}

//Overload operator *, Multiplies a fraction and an int;
Fraction Fraction::operator* (int f2) const
{
	return Fraction(Numerator * f2, Denominator);
}

//Overload operator /, Divide 2 fractions;
Fraction Fraction::operator/ (const Fraction& f2) const
{
	return Fraction(Numerator * f2.getDenominator(), Denominator * f2.getNumerator());
}

//Overload operator /, Divide a fraction and an int;
Fraction Fraction::operator/ (int f2) const
{
	return Fraction(Numerator, Denominator * f2);
}

//Overload operator +=, Add a fraction to the operator owner fraction.
Fraction& Fraction::operator+= (const Fraction& f2)
{
	Numerator = Numerator*f2.getDenominator() + f2.getNumerator()*Denominator;
	Denominator = Denominator * f2.getDenominator();
	return *this;
}

//Overload operator -=, Subtract a fraction from the operator owner fraction.
Fraction& Fraction::operator-= (const Fraction& f2)
{
	Numerator = Numerator*f2.getDenominator() - f2.getNumerator()*Denominator;
	Denominator = Denominator * f2.getDenominator();
	return *this;
}

//Overload operator *=, Multiplies a fraction with the operator owner fraction.
Fraction& Fraction::operator*= (const Fraction& f2)
{
	Numerator = Numerator * f2.getNumerator();
	Denominator = Denominator * f2.getDenominator();
	return *this;
}

//Overload operator /=, Divide a fraction from the operator owner fraction.
Fraction& Fraction::operator/= (const Fraction& f2)
{
	Numerator = Numerator * f2.getDenominator();
	Denominator = Denominator * f2.getNumerator();
	return *this;
}

//Overload operator >, Return true if the left fraction is bigger otherwise return false;
bool Fraction::operator> (const Fraction& f2) const
{
	return (float)*this > (float)f2 ? true : false;
}

//Overload operator >=, Return true if the left fraction is bigger or equal otherwise return false;
bool Fraction::operator>= (const Fraction& f2) const
{
	return (float)*this >= (float)f2 ? true : false;
}

//Overload operator <, Return true if the left fraction is smaller otherwise return false;
bool Fraction::operator< (const Fraction& f2) const
{
	return (float)*this < (float)f2 ? true : false;
}

//Overload operator <=, Return true if the left fraction is smaller or equal otherwise return false;
bool Fraction::operator<= (const Fraction& f2) const
{
	return (float)*this <= (float)f2 ? true : false;
}

//Overload operator ==, Return true if the fractions are equal otherwise return false;
bool Fraction::operator== (const Fraction& f2) const
{
	return (float)*this == (float)f2 ? true : false;
}

//Overload operator !=, Return true if the fractions are not equal otherwise return false;
bool Fraction::operator!= (const Fraction& f2) const
{
	return (float)*this != (float)f2 ? true : false;
}

//Overload operator ++, Increase fraction by 1 (Numerator += Denominator);
Fraction& Fraction::operator++ ()
{
	Numerator += Denominator;
	return *this;
}

//Overload operator --, Decrease fraction by 1 (Numerator -= Denominator);
Fraction& Fraction::operator-- ()
{
	Numerator -= Denominator;
	return *this;
}

//Overload operator - (Unary), Return the opposite fraction (negative value);
Fraction Fraction::operator- () const
{
	return Fraction(-Numerator, Denominator);
}

//Overload operator (int), Convert fraction to integer.
Fraction::operator int() const
{
	return (Numerator / Denominator);
}

//Overload operator (float), Convert fraction to float.
Fraction::operator float() const
{
	return ((float)(Numerator) / (float)(Denominator));
}
