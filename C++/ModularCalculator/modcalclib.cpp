#include "modcalclib.h"

using namespace std;

//Set the value of PI
const double PI = 3.141592653589793238462;

//Set the number of operations. later to be used in the list of operations.
const int OPERATIONSCOUNT = 10;
//Set a list with the basic keywords for the Set operation, to be used in the Set operation initialization.
vector<string> Set_Operations = { "=", "Set" };
//Set a list with the basic keywords for the Addition operation, to be used in the Addition operation initialization.
vector<string> Add_Operations = { "+", "Add" };
//Set a list with the basic keywords for the Subtraction operation, to be used in the Subtraction operation initialization.
vector<string> Subtract_Operations = { "-", "Subtract" };
//Set a list with the basic keywords for the Multiplication operation, to be used in the Multiplication operation initialization.
vector<string> Multiple_Operations = { "*", "Multiple" };
//Set a list with the basic keywords for the Division operation, to be used in the Division operation initialization.
vector<string> Divide_Operations = { "/", "Divide" };
//Set a list with the basic keywords for the Root operation, to be used in the Root operation initialization.
vector<string> Root_Operations = { "R", "Root" };
//Set a list with the basic keywords for the Power operation, to be used in the Power operation initialization.
vector<string> Pow_Operations = { "^", "Pow" };
//Set a list with the basic keywords for the Sine operation, to be used in the Sine operation initialization.
vector<string> Sin_Operations = { "Sin" };
//Set a list with the basic keywords for the Cosine operation, to be used in the Cosine operation initialization.
vector<string> Cos_Operations = { "Cos" };
//Set a list with the basic keywords for the Tangent operation, to be used in the Tangent operation initialization.
vector<string> Tan_Operations = { "Tan" };

//Initializes an array of pointers to the base abstract operation class, full with all the different derived operations and returns it.
CalculatorOperation ** InitializeOperations()
{
	static CalculatorOperation * Operations[OPERATIONSCOUNT];
	Operations[0] = new OpSet(Set_Operations);
	Operations[1] = new OpAdd(Add_Operations);
	Operations[2] = new OpSubtract(Subtract_Operations);
	Operations[3] = new OpMultiple(Multiple_Operations);
	Operations[4] = new OpDivide(Divide_Operations);
	Operations[5] = new OpRoot(Root_Operations);
	Operations[6] = new OpPow(Pow_Operations);
	Operations[7] = new OpSin(Sin_Operations);
	Operations[8] = new OpCos(Cos_Operations);
	Operations[9] = new OpTan(Tan_Operations);
	return Operations;
}

//Gets an array of pointer to the base abstract class and free its memory.
void FreeOperations(CalculatorOperation ** Operations)
{
	for (int i = 0; i < OPERATIONSCOUNT; i++)
	{
		delete Operations[i];
	}
}

/*get a string, contains an input from the user, seperate it to the keywords and parameters 
and returns them as seperate strings in a vector.*/
vector<string> GetCommandParameters(string command)
{
	vector<string> parameters;
	unsigned int i = 0;
	string param;
	while (i < command.length())
	{
		if (command[i] != ' ')
		{
			param += command[i];
			i++;
			if (i == command.length())
			{
				parameters.push_back(param);
			}
		}
		else
		{
			i++;
			parameters.push_back(param);
			param.clear();
		}
	}

	return parameters;
}

/*Get an array with the different operations and a string with a keyword, 
if the keyword matches an operation, return its index in the array, otherwise return -1*/
int GetOperationID(CalculatorOperation ** operations, string op_string)
{
	for (int i = 0; i < OPERATIONSCOUNT; i++)
	{
		if (operations[i]->SupportsOperation(op_string))
		{
			return i;
		}
	}
	return -1;
}

//Print message full of useful information abut how to use the calculator (operations and syntax)
void PrintHelp(CalculatorOperation ** operations)
{
	for (int i = 0; i < OPERATIONSCOUNT; i++)
	{
		cout << operations[i]->About() << "\n===============================\n";
	}
	cout << "Calculator Syntax: [Operation] [param1] [param2]... [paramN]\n";
	cout << "Add Operation Keyword: $New [Operation_Exist_Keyword] [New_Operation_Keyword]\n";
	cout << "Store current value in memory: $Store\n";
	cout << "Use stored memory value: $Mem\n";
}