#if !defined FRACTION_H_
#define FRACTION_H_

using namespace std;

//Class representing a fraction, with different functions and operatos to perform on the fraction
class Fraction
{
public:
	//Empty C'tor, set an empty Fraction.
	Fraction() {};
	//C'tor, Get a numerator and denominator and set them to the fraction, if denominator not passed, set it as 1;
	Fraction(int numerator, int denominator = 1) : Numerator(numerator), Denominator(denominator) {}
	//D'tor
	~Fraction() {}
	//Return the numerator
	int getNumerator() const;
	//Get a number and Set the numerator
	void setNumerator(int numerator);
	//Get the denominator
	int getDenominator() const;
	//Get a number and Set the denominator
	void setDenominator(int denominator);
	//Reduce the fraction to the smallest value possible.
	void Reduce();
	//Prints the fraction.
	void print() const;

	//Overload operator +, add 2 fractions;
	Fraction operator+ (const Fraction& f2) const;
	//Overload operator +, add a fraction and an int;
	Fraction operator+ (int f2) const;
	//Overload operator -, subtract 2 fractions;
	Fraction operator- (const Fraction& f2) const;
	//Overload operator -, subtract a fraction and an int;
	Fraction operator- (int f2) const;
	//Overload operator *, Multiplies 2 fractions;
	Fraction operator* (const Fraction& f2) const;
	//Overload operator *, Multiplies a fraction and an int;
	Fraction operator* (int f2) const;
	//Overload operator /, Divide 2 fractions;
	Fraction operator/ (const Fraction& f2) const;
	//Overload operator /, Divide a fraction and an int;
	Fraction operator/ (int f2) const;
	//Overload operator +=, Add a fraction to the operator owner fraction.
	Fraction& operator+= (const Fraction& f2);
	//Overload operator -=, Subtract a fraction from the operator owner fraction.
	Fraction& operator-= (const Fraction& f2);
	//Overload operator *=, Multiplies a fraction with the operator owner fraction.
	Fraction& operator*= (const Fraction& f2);
	//Overload operator /=, Divide a fraction from the operator owner fraction.
	Fraction& operator/= (const Fraction& f2);
	//Overload operator >, Return true if the left fraction is bigger otherwise return false;
	bool operator> (const Fraction& f2) const;
	//Overload operator >=, Return true if the left fraction is bigger or equal otherwise return false;
	bool operator>= (const Fraction& f2) const;
	//Overload operator <, Return true if the left fraction is smaller otherwise return false;
	bool operator< (const Fraction& f2) const;
	//Overload operator <=, Return true if the left fraction is smaller or equal otherwise return false;
	bool operator<= (const Fraction& f2) const;
	//Overload operator ==, Return true if the fractions are equal otherwise return false;
	bool operator== (const Fraction& f2) const;
	//Overload operator !=, Return true if the fractions are not equal otherwise return false;
	bool operator!= (const Fraction& f2) const;
	//Overload operator ++, Increase fraction by 1 (Numerator += Denominator);
	Fraction& operator++ ();
	//Overload operator --, Decrease fraction by 1 (Numerator -= Denominator);
	Fraction& operator-- ();
	//Overload operator - (Unary), Return the opposite fraction (negative value);
	Fraction operator- () const;
	//Overload operator (int), Convert fraction to integer.
	operator int() const;
	//Overload operator (float), Convert fraction to float.
	operator float() const;
	//Overload operator << (for cin), let the user print a fraction using the std::cout.
	inline friend ostream& operator<< (ostream& os, const Fraction& f)
	{
		if (f.Denominator == 1)
		{
			os << f.Numerator;
		}
		else
		{
			os << f.Numerator << "/" << f.Denominator;
		}
		return os;
	}
	/*Overload operator >> (for std::cin), let the user input a fraction using the std::cin.
	Syntax: cin << Numerator/Denominator;*/
	inline friend istream& operator>> (istream& is, Fraction& f)
	{
		char slash;
		is >> f.Numerator >> slash >> f.Denominator;
		return is;
	}

private:
	//The fraction's numerator is stored here.
	int Numerator;
	//The fraction's denominator is stored here. 
	int Denominator;
	//private function, get 2 numbers and return their greatest common divisor (used or reduce function).
	int getGreatestCommonDivisor(int a, int b);
};

#endif