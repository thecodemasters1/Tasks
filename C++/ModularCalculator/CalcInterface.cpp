#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include "modcalclib.h"

using namespace std;

//The main function, holding the Modular Calculator interface and manages it. 
int main(int argc, char * argv[])
{
	//Get the list of avaliable operations and their keywords.
	CalculatorOperation ** OperationsList = InitializeOperations();
	//Initialize value to 0
	double val = 0, stored = 0;
	//string to store the user's selection
	string select;
	cout << "##### _  _ ____ ___    ____ ____ _    ____ #####\n" <<
		"##### |\\/| [__] |__>   |___ |--| |___ |___ #####\n" <<
		"#####                                      #####\n";

	cout << "Welcome to the \"Module Calculator\"!\nType \"Help\" to see the available commands.\nType \"Exit\" to exit the calculator.\n";
	cout << "Calculator Syntax: [Operation] [param1] [param2]... [paramN]\n";
	cout << "Add Operation Keyword: $New [Operation_Exist_Keyword] [New_Operation_Keyword]";
	cout << "Store current value in memory: $Store\n";
	cout << "Use stored memory value: $Mem\n";
	cout << "\n==============================================\n";
	while (select != "Exit")
	{
		cout << "\nCurrent Value: " << val << "\n";
		cout << "Enter Operation (\"Exit\" - Exit, \"Help\" - Commands): ";
		//selected operation index in the array will be stored here.
		int selectedOperation = -1;
		//get input from the user.
		getline(cin, select);
		vector<string> commandParameters = GetCommandParameters(select);
		//Check if one or more of the parameters is the stored keyword $Mem, if so, replace it with "stored" value.
		for (int i = 0; i < commandParameters.size(); ++i)
		{
			if (commandParameters[i] == "$Mem")
			{
				commandParameters[i] = to_string(stored);
			}
		}
		if (commandParameters.size() != 0) //if input is not empty
		{
			if (commandParameters[0] == "$New") //if input start with the $New keyword
			{
				commandParameters.erase(commandParameters.begin()); //remove the keyword from the command parameters' list
				if (commandParameters.size() == 2) //check if there is a correct input to the $New keyword
				{
					selectedOperation = GetOperationID(OperationsList, commandParameters[0]); //find the operation to add the new keyword into 

					if (selectedOperation != -1) //if operation is found
					{
						commandParameters.erase(commandParameters.begin());
						//Check if the new keyword is not already in use, and if not, add the new keyword.
						if (GetOperationID(OperationsList, commandParameters[0]) == -1 && commandParameters[0] != "$New"
							&& commandParameters[0] != "$Store" && commandParameters[0] != "$Mem")
						{
							OperationsList[selectedOperation]->AddOperation(commandParameters[0]);
							cout << "Keyword added.\n";
						}
						else //otherwise, if keyword is in use, print a message to the user.
						{
							cout << "Keyword already exists.\n";
						}
					}
					else //if not, print a message to the user
					{
						cout << "Operation for the new keyword not found.\n";
					}
				}
				else //if syntax for the $New keyword is invalid.
				{
					cout << "$New keyword syntax is invalid | Syntax: $New [Operation_Exist_Keyword] [New_Operation_Keyword].\n";
				}
			}
			else if (commandParameters[0] == "$Store") //if input start with the $Store Keyword
			{
				//store the current value in memory - stored and print a message to the user.
				stored = val;
				cout << "Stored current value to memory, use the keyword $Mem to use it\n";
			}
			else
			{
				selectedOperation = GetOperationID(OperationsList, commandParameters[0]); //check the input to find the selcted operation

				if (selectedOperation != -1) //if operation is found
				{
					commandParameters.erase(commandParameters.begin());
					//check if user passed enough parameters for the choosen operation
					if (commandParameters.size() >= OperationsList[selectedOperation]->RequiredParameters())
					{
						//update the value in the calculator by the selected operation.
						val = OperationsList[selectedOperation]->CalcResult(val, commandParameters);
					}
					else //if not enough parameters have been passed.
					{
						cout << "Not enough parameters for the required operation.\n";
					}
				}
				else if (select == "Help") //if input is "Help" print the help message.
				{
					PrintHelp(OperationsList);
				}
				else if (select == "Exit") //if input is "Exit" break from the loop and continue to the program's end.
				{
					continue;
				}
				else //if no operation is found
				{
					cout << "Unkown operation keyword.\n";
				}
			}
		}
		else //if input is empty
		{
			cout << "No operation keyword detected.\n";
		}
	}
	cout << "\nExiting...\n";
	//Call the operations list's memory free function;
	FreeOperations(OperationsList);
}