#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "OpSet.h"
#include "OpAdd.h"
#include "OpSubtract.h"
#include "OpMultiple.h"
#include "OpDivide.h"
#include "OpRoot.h"
#include "OpPow.h"
#include "OpSin.h"
#include "OpCos.h"
#include "OpTan.h"

using namespace std;
//Include the basic functions and settings required for the modular calculator.

//const double with the value of PI - 3.141592653589793238462
extern const double PI;
//const int with the number of operations classes - 10
extern const int OPERATIONSCOUNT;
//vector with the basic Set keywords - = Set
extern vector<string> Set_Operations;
//vector with the basic Addition keywords - + Add
extern vector<string> Add_Operations;
//vector with the basic Subtraction keywords - - Subtract
extern vector<string> Subtract_Operations;
//vector with the basic Multiplication keywords - * Multiple
extern vector<string> Multiple_Operations;
//vector with the basic Division keywords - / Divide
extern vector<string> Divide_Operations;
//vector with the basic Root keywords - = R Root
extern vector<string> Root_Operations;
//vector with the basic Power keywords - ^ Pow
extern vector<string> Pow_Operations;
//vector with the basic Sine keywords - Sin
extern vector<string> Sin_Operations;
//vector with the basic Cosine keywords - Cos
extern vector<string> Cos_Operations;
//vector with the basic Tangent keywords - Tan
extern vector<string> Tan_Operations;

//Initializes an array of pointers to the base abstract operation class, full with all the different derived operations and returns it.
CalculatorOperation ** InitializeOperations();
//Gets an array of pointer to the base abstract class and free its memory.
void FreeOperations(CalculatorOperation ** Operations);
/*get a string, contains an input from the user, seperate it to the keywords and parameters
and returns them as seperate strings in a vector.*/
vector<string> GetCommandParameters(string command);
/*Get an array with the different operations and a string with a keyword,
if the keyword matches an operation, return its index in the array, otherwise return -1*/
int GetOperationID(CalculatorOperation ** operations, string op_string);
//Print message full of useful information abut how to use the calculator (operations and syntax)
void PrintHelp(CalculatorOperation ** operations);