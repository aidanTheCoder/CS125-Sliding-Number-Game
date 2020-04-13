#ifndef SLIDEGAME_H
#define SLIDEGAME_H

//define constants
#define COLUMNS 4
#define ROWS 4

//function prototypes
void popArray(int Array[COLUMNS][ROWS]);
int checkArray(int Array[COLUMNS][ROWS], int check);
void randArray(int Array[COLUMNS][ROWS]);
int userInput();
int endGame(int playerArray[ROWS][COLUMNS]);
void printBoard(int game[ROWS][COLUMNS]);
void findNot(int game[ROWS][COLUMNS], int *xNot, int *yNot);
void clearScreen();
void startGame();
int solveCheck(int gameArray[COLUMNS][ROWS]);
void gameOver();

#endif
