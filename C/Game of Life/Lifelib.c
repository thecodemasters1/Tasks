#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lifelib.h"

static int UpdateCell(Board board, int row, int col);
static int LiveNeighbors(Board board, int x, int y);
static void cpyBoard(Board dest, Board source);

/*Get number of rows and cols and return a board struct with a 
2D array (rows*cols) full of dead cells
~this function is making use of the following function(s): ClearBoard~ */
Board initializeBoard(int rows, int cols)
{
	int i;
	Board board;
	board.rows = rows;
	board.cols = cols;
	board.data = malloc(board.rows*sizeof(int *));
	for (i = 0; i < board.rows; i++)
	{
		board.data[i] = (int *)malloc(board.cols*sizeof(int));
	}
	ClearBoard(board);

	return board;
}

/*Get a Board and clear set the cells as dead. */
void ClearBoard(Board board)
{
	int i, j;
	for (i = 0; i < board.rows; ++i)
	{
		for (j = 0; j <board.cols; ++j)
		{
			board.data[i][j] = 0;
		}
	}
}

/*Free the memory that has been allocated to the board */
void freeBoard(Board board)
{
	int i;
	for (i = 0; i < board.rows; ++i)
	{
		free(board.data[i]);
	}
	free(board.data);
	board.rows = 0;
	board.cols = 0;
}

/*Recieves a board and implement the rule of life on it.
~this function is making use of the following function(s): updateCell, cpyBoard, freeBoard~ */
void UpdateBoard(Board board)
{
	int i, j;
	Board newBoard = initializeBoard(board.rows, board.cols);
	for (i = 0; i < board.rows; ++i)
	{
		for (j = 0; j < board.cols; ++j)
		{
			newBoard.data[i][j] = UpdateCell(board, i, j);
		}
	}
	cpyBoard(board, newBoard);
	freeBoard(newBoard);
}

/*recieves a specific index of a cell in a board and a board and implement the rule of life on it.
~this function is making use of the following function(s): LiveNeighbors~ */
static int UpdateCell(Board board, int row, int col)
{
	int lc = LiveNeighbors(board, row, col);
	switch (lc)
	{
	case 2:
		return board.data[row][col];
		break;
	case 3:
		return 1;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}

/*recieves a specific index of a cell in a board and a board and count the living neighbors of the cell. */
static int LiveNeighbors(Board board, int row, int col)
{
	int lc = 0;
	int i, j;
	for (i = max(0, row - 1); i <= min(row + 1, board.rows - 1); ++i)
	{
		for (j = max(0, col - 1); j <= min(col + 1, board.cols - 1); ++j)
		{
			if ((i != row || j != col) && board.data[i][j] == 1)
			{
				lc++;
			}
		}
	}
	return lc;
}

/*This function recieves 2 boards and copy the source board to the dest board. */
static void cpyBoard(Board dest, Board source)
{
	int i, j;
	for (i = 0; i < dest.rows; ++i)
	{
		for (j = 0; j < dest.cols; ++j)
		{
			dest.data[i][j] = source.data[i][j];
		}
	}
}

/*This function recieves a board and prints it as a matrix */
void printBoard(Board board)
{
	int i, j;
	for (i = 0; i < board.rows; ++i)
	{
		for (j = 0; j < board.cols; ++j)
		{
			printf("%d", board.data[i][j]);
		}
		printf("\n");
	}
}

/*This function recieves a board and a cell index and change it status (Dead-Alive) */
void changeCell(Board board, int row, int col)
{
	if (board.data[row][col] == 0)
	{
		board.data[row][col] = 1;
	}
	else
	{
		board.data[row][col] = 0;
	}
}

/*This function recieves a board and return the number of living cells in it. */
int countLiveCells(Board board)
{
	int lc = 0;
	int i, j;
	for (i = 0; i < board.rows; ++i)
	{
		for (j = 0; j <board.cols; ++j)
		{
			if (board.data[i][j] == 1)
			{
				lc++;
			}
		}
	}
	return lc;
}