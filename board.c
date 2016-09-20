/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : Wolf Zimmermann
* Student Number   : S3495671
* Course Code      : Cosc1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"
#include "player.h"

/**
 * @file board.c contains implementations of functions related to the game 
 * board.
 **/

/**
 * @param board the board to reset the contents of
 **/
 /* At each row the function will then go through all coloumns and 
  * assignt the value C_EMPTY. It will then move up a row and repeat.
   */
void initialise_board(enum cell_contents board[][BOARDWIDTH])
{
	int height ,width;
	/*go through the rows*/
    for(height = 0; height <BOARDHEIGHT; height++){
			/*go through the columns*/
			
        for(width = 0; width < BOARDWIDTH; width++){
				
		board[height][width] = C_EMPTY;
		}
}
}

/**
 * In this requirement you are required to display the game board. 
 * The game board should be displayed as shown on the first page of the 
 * assignment specification. 
 * @param board the board to display
 **/
void display_board(enum cell_contents board[][BOARDWIDTH])
{
	int row, col,i;
	for(i = 1; i <= BOARDWIDTH ; i++){
		printf("| %i ",i);
	}
	printf("|");
	printf("\n-------------------------------\n");
	for(row = 0; row < BOARDHEIGHT; row++){
		for(col = 0; col < BOARDWIDTH; col++){
			if (board[row][col] == C_EMPTY){
				printf("|   ");
			}
			else if(board[row][col] == C_RED){
			printf("| %s ",RED_TOKEN);
			}
			else if(board[row][col] == C_WHITE){
			printf("| %s ",WHITE_TOKEN);
			}
		}
	printf("|");
	printf("\n-------------------------------\n");
	}
	}
	
	


 

