#if !defined LIFELIB_H_
#define LIFELIB_H_

/*This structs define a board in the game of life, with number of rows and cols 
and a 2D array of cells, with values of 0-Dead and 1-Alive*/
struct _board
{
	int rows;
	int cols;
	int ** data;
};

typedef struct _board Board;

Board initializeBoard(int rows, int cols);
void ClearBoard(Board board);
void freeBoard(Board board);
void UpdateBoard(Board board);
void printBoard(Board board);
void changeCell(Board board, int row, int col);
int countLiveCells(Board board);

#endif