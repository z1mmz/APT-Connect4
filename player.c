/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : Wolf Zimmermann
* Student Number   : S3495671
* Course Code      : Cosc1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{
int Slen;
    char name[NAMELEN +1];
	BOOLEAN isValid = FALSE;
	while(isValid == FALSE){
    printf("Please enter your name: ");
    fgets(name,NAMELEN + 2,stdin);
		if(name[strlen(name) - 1] != '\n'){
			printf("Input invalid");
			read_rest_of_line();
			isValid = FALSE;
		}else
		{
		Slen = strlen(name);
				if(name[Slen - 1] == '\n'){
					name[Slen - 1] = '\0';
				}
			strcpy((*human).name,name);
			(*human).thiscolor = C_RED;
			(*human).counters = 0;
			(*human).type = 1;
			isValid = TRUE;
		}
    /* placeholder return value. You should prompt the user 
     * for their name and then initialise all other values in the
     * player struct to sensible values.
     */
	 }
    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
    /* initialise all variables that are part of the struct to sensible 
     * values */
	 strcpy((*computer).name, "computer");
	 (*computer).thiscolor = C_WHITE;
	 (*computer).counters = 0;
	 (*computer).type = 0;
	 

    return SUCCESS;
}

/**
 * In this requirement, you need to handle the taking of a turn - either
 * of a human or a computer player.
 *
 * For the human player, you will need to allow the user to enter the 
 * column they wish to place a token in. You will need to validate what 
 * the user enters, then place a token correctly in that column so that
 * it occupies the cell closest to the bottom of the board array for that 
 * column.
 *
 * For the computer player, you will need to randomly generate a column 
 * number to place a token in and if that column is full, generate a 
 * different column number until a column number with some free space has 
 * been found.
 *
 * @param current the current player
 * @param board the game board that we will attempt to insert a token into
 * @return enum @ref input_result indicating the state of user input (in 
 * case this run involved user input
 **/
enum input_result take_turn(struct player * current,
        enum cell_contents board[][BOARDWIDTH])
{	
	char selectedColumn[3];
	int column;
	int Slen;
	int i;
	char * endPtr;
	int inputValid = 0;
	/*HUMAN PLAYER TURN*/
   if((*current).type == 1){
		while (inputValid == 0){
			printf("Select a column for your token: ");
			fgets(selectedColumn,3,stdin);
			if(selectedColumn[strlen(selectedColumn) - 1] != '\n'){
					printf("Input invalid");
					read_rest_of_line();
					
				}else{
						Slen = strlen(selectedColumn);
						if(selectedColumn[Slen - 1] == '\n'){
							selectedColumn[Slen - 1] = '\0';
						}
						column = strtol(selectedColumn,&endPtr,10);
						if(endPtr == '\0'){
							
						}else{
						
							if(column > 7 || column <= 0  ){
								printf("Input is not within 1 - 7\n");
								
							}else {if(board[0][column -1] == C_EMPTY){
									inputValid = 1;
									/*Take one off as we are dealing with an array starting
									from 0 but we are displaying to the user 1-7*/
									if(column != 0){
										column--;
									}
									}
							}
						}
					}
		}
						for(i = 5; i >=0; i--){
						
							if(board[i][column] == C_EMPTY){
							
								board[i][column] = C_RED;
								(*current).counters +=1;
								printf("%i",(*current).counters );
								
								return SUCCESS;
							}	
						}
						
	
			
		
	}else{
	/*COMPUTER PLAYER TURN*/
		
		int i;
		while(1==1){
		column = rand() % (8 + 0 - 1) + 0;
			for(i = BOARDHEIGHT -1 ; i >=0; i--){
				if(board[i][column] == C_EMPTY){
					board[i][column] = C_WHITE;
					
					return SUCCESS;
				}
			}
			}
			display_board(board);
	}
	
	display_board(board);
	return FAILURE;
	
}


