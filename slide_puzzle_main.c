#include "slidegame.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{   
    //time_t structure from time.h
    time_t start, end; 
    //starts the timer for the board  
    start = time(NULL);
    srand(time(NULL));
    FILE * gameRecord = fopen("your_games.txt","a");
    //xPos,yPos,xNot,yNot were place holders for coordinates on board
    int move=0, xNot=0, yNot=0,xPos = 0,yPos = 0;
    int game[4][4];
    //generates random array
    randArray(game);
    fprintf(gameRecord,"\n\n");
    //double for loop writes the initial board to your_games.txt
    for (yPos = 0; yPos < ROWS; yPos++) {
        for (xPos = 0; xPos < COLUMNS; xPos++) {
            if (game[yPos][xPos]!=0){
                fprintf(gameRecord, "%4d", game[yPos][xPos]);
            }
            else{ 
                fprintf(gameRecord,"    ");
            }
        }
        fprintf(gameRecord,"\n");
    }      
    //finds the blank spot on the game board 
    findNot(game, &xNot, &yNot);
    //starts the game
    while(endGame(game) == 0){
        //user input returns an int with the direction to move
        move=userInput(); 
        if(move == 1){
            //checks if the empty spot is on the edge of the board
            if(yNot !=3){
                //moves the previous value into the empty spot
                game[yNot][xNot] = game[yNot+1][xNot];
                //changes the previous value to 0 (empty spot)
                game[yNot+1][xNot] = 0;
                yNot=yNot+1;
            }
        }
        //refer to previous comments for more info
        if(move == 2){
            if(xNot !=3){
                game[yNot][xNot] = game[yNot][xNot+1]; 
                game[yNot][xNot+1] = 0;
                xNot=xNot+1;
            }
        }
        if(move == 3){
            if(yNot !=0){
                game[yNot][xNot] = game[yNot-1][xNot]; 
                game[yNot-1][xNot] = 0;
                yNot=yNot-1;
            }
        }
        if(move == 4){
            if(xNot !=0){
                game[yNot][xNot] = game[yNot][xNot-1]; 
                game[yNot][xNot-1] = 0;
                xNot=xNot-1;
            }
        }
        printf("\n");
    }
    //ends the timer
    end = time(NULL);
    printBoard(game);
    //prints game over graphics
    gameOver();
    printf("\n\n                Congratulations! Your time is %.0f seconds!\n\n\n\n\n", difftime(end, start));
    //records the time taken to solve
    fprintf(gameRecord,"You solved the puzzle in %.0f seconds! \n",difftime(end,start));
    fclose(gameRecord);
    return 0;
}

