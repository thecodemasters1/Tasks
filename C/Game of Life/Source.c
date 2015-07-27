#include <stdio.h>
#include "Lifelib.h"

#define TRUE 1
#define FALSE 0
#define FILE_OPENED 0
#define COULDNT_OPEN_FILE -1
#define COULDNT_CLOSE_FILE -2


/* An implementation of the "Game of Life" 
The main function may recieve a txt file to save the result board to, otherwise, result will not be saved.
Board size and starting situation is set via the console on runtime.
The user may choose when to stop the "game", meaning he can choose how many times to implement the rule of the "game"
*/
int main(int argc, char * argv[])
{
	FILE * f = NULL;
	int browSize, bcolSize;
	Board board;
	int row, col;
	int i, j;
	int ans, newLiveCell = TRUE;
	int runLoop = TRUE;
	int fileOpend = 0;

	printf(" _____                          ___    _  _  ___      \n"
		"|   __| ___  _____  ___    ___ |  _|  | ||_||  _| ___ \n"
		"|  |  || .'||     || -_|  | . ||  _|  | || ||  _|| -_|\n"
		"|_____||__,||_|_|_||___|  |___||_|    |_||_||_|  |___|\n\n"
		"======================================================\n\n");

	printf("Welcome to the game of life!\n");
	if (argc != 2)
	{
		printf("*NOTE: You can pass a text file via the command line and export your final board to it.*\n");
	}
	else
	{
		printf("Board save file was passed, attemping to open file...\n");
		if ((fileOpend = fopen_s(&f, argv[1], "w")) != FILE_OPENED)
		{
			printf("Couldn't open save file, continue to run without saving? 1-YES | 0-No ");
			scanf_s("%d", &ans);
			if (ans == FALSE)
				return COULDNT_OPEN_FILE;
		}
		else
		{
			printf("Board save file was opened successfully!\n");
		}
	}
	printf("please enter the board settings\nEnter number of rows in board: ");
	scanf_s("%d", &browSize);
	printf("Enter number of cols in board: ");
	scanf_s("%d", &bcolSize);

	board = initializeBoard(browSize, bcolSize);
	printBoard(board);

	while (newLiveCell == TRUE)
	{
		printf("\nAdd new live cell? 1-YES | 0-NO ");
		scanf_s("%d", &ans);
		if (ans == FALSE)
			break;
		printf("\n\n*NOTE: to kill a live cell, just reselect it.*\nEnter cell's row: ");
		scanf_s("%d", &row);
		printf("Enter cell's col: ");
		scanf_s("%d", &col);
		changeCell(board, row, col);
		printBoard(board);
	}

	printf("\nPress enter to apply the rule of life and begin. \nPress any other key and then enter to exit.\n");
	if (getc(stdin) != '\n')
		runLoop = FALSE;

	while (runLoop == TRUE)
	{
		UpdateBoard(board);
		printBoard(board);
		printf("\nPress enter to apply the rule of life again. \nPress any other key and then enter to exit.\n");
		if (getc(stdin) != '\n')
			runLoop = FALSE;
	}

	if (argc == 2 && f != NULL)
	{
		for (i = 0; i < board.rows; ++i)
		{
			for (j = 0; j < board.cols; ++j)
			{
				fputc('0' + board.data[i][j], f);
			}
			fputc('\n', f);
		}
		freeBoard(board);

		if (fclose(f) != 0)
		{
			printf("Couldn't close the save file.\n");
			return COULDNT_CLOSE_FILE;
		}
		printf("Final board was successfully saved and closed.\n");
	}
	printf("Run has ended.\n");
	return 0;
}