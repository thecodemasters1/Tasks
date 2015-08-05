#include <iostream>
#include <string>
#include "Beer.h"
#include "RedWine.h"
#include "WhiteWine.h"

using namespace std;

//Number of drinks in the stock
const int STOCKSIZE = 11;

//Returns an array the size of STOCKSIZE with the different drinks in the bar.
Drink ** InitializeStock();

//Get an array with the drink stock and free its memory.
void FreeStock(Drink ** Stock);

//The main function, represent a person that enters the bar and order different drinks, manages the program's operation.
int main(int argc, char * argv[])
{
	//an array representing the stock in the bar.
	Drink ** Stock = InitializeStock();
	//user input will be stored here to check input.
	string choiceTest;
	//Right user input will then be casted to int and stored here.
	int choice = 0;
	//Index of the last drink ordered.
	int LastDrink = 0;
	//while the input is different than 100, the "Exit" input, "the bar is open"
	while (choice != 100)
	{
		//Make sure the input it right.
		try
		{
			cout << "What can I get you, sir? (0 - list options)\n";
			//take the user input and store it to "choiceTest"
			cin >> choiceTest;
			//try to convert the input to int and store it in "choice", on failure throw Invalid_Arguments"
			choice = stoi(choiceTest);
			//if input is fine, test the user's choice and return the correct option reaction.
			switch (choice)
			{
			case 0: //display the list of options.
				cout << "0 | list options\n";
				for (int i = 0; i < STOCKSIZE; i++)
				{
					cout << i + 1 << " | " << Stock[i]->getName() << "\n";
				}
				cout << "99 | How did you prepare my last drink?\n";
				cout << "100 | Leave the bar\n\n";
				break;
			case 99: //display the how to prepare message of the last drink.
				Stock[LastDrink]->prepare();
				cout << "\n";
				break;
			case 100: //"Close the bar", print a message to the user and continue to the end of the program
				cout << "Bar is closed. Good night.\n";
				break;
			default: //otherwise, check if input matches a stock drink and then serve it, otherwise prints a message for the user - unkown option
				if (choice >= 1 && choice <= STOCKSIZE)
				{
					cout << "One " << Stock[choice - 1]->getName() << " coming up, sir.\n\n";
					LastDrink = choice - 1;
				}
				else
				{
					cout << "Unkown option selected, sir.\n\n";
				}
				break;
			}
		}
		//if the input was indded NaN, prints a message to the user.
		catch (...)
		{
			cout << "Input is invalid\n\n.";
		}
	}

	//Free the stock's memory
	FreeStock(Stock);
	return 0;
}

//Returns an array the size of STOCKSIZE with the different drinks in the bar.
Drink ** InitializeStock()
{
	static Drink *Stock[STOCKSIZE];
	Stock[0] = new Beer("Heineken");
	Stock[1] = new Beer("Carlsberg");
	Stock[2] = new Beer("Maccabi");
	Stock[3] = new Beer("Tuborg");

	Stock[4] = new WhiteWine("Carmel Emerald Riesling", 1986);
	Stock[5] = new WhiteWine("Golan Smadar", 1989);
	Stock[6] = new WhiteWine("Yarden Shredona", 1997);

	Stock[7] = new RedWine("Chianti", 1997);
	Stock[8] = new RedWine("Yarden Mout. Hermon Red", 1994);
	Stock[9] = new RedWine("Yarden Cabernet Sauvignon", 1997);
	Stock[10] = new RedWine("Chadeau Margot", 1997);

	return Stock;
}

//Get an array with the drink stock and free its memory.
void FreeStock(Drink ** Stock)
{
	for (int i = 0; i < STOCKSIZE; i++)
	{
		delete Stock[i];
	}
}