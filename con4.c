/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : Wolf Zimmermann
* Student Number   : S3495671
* Course Code      : Cosc1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"
#include <stdio.h>
#include "scoreboard.h"
#include "helpers.h"
#include <time.h>
/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the 
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and 
 * respond to user requests.
 *
 * The main menu should look like this: 
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from 
 * running an option.
 **/
int main(void)
{
	
	char choice[3] = "";
	BOOLEAN isQuit = FALSE;
	int random;
	enum input_result InputResult;
	/*color board[BOARDHEIGHT][BOARDWIDTH];*/
    /* the scoreboard for keeping track of winners */
    scoreboard scores;
	
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;

    /* with each of the comments below, insert the code that performs 
     * this function 
    initialise the scoreboard */
	init_scoreboard(scores);
    /*display menu and get menu choice until the user chooses to quit */
	isQuit = FALSE;
	while(1==1){
		BOOLEAN inputValid = FALSE;
		while(inputValid == FALSE){
			
			printf("%s\n%s\n%s\n%s\n%s\n%s","Wecome to connect 4 ver 2","\n--------------------------",
					"1. Play Game","2. Display High Scores","3. Quit","please enter your choice: ");
			
			InputResult = get_Input(choice);

			if (InputResult == SUCCESS){
				if (!(choice[0] == '1' || choice[0] ==  '2' || choice[0] ==  '3')){
					printf("Not vaild\n\n");
				}
				else{
					inputValid = TRUE;
				}
			}
			/*fgets(choice,3,stdin);
			if(choice[strlen(choice) - 1] != '\n'){
				printf("Input invalid");
				read_rest_of_line();
			}
			else{
				Check if input is a valid selection
				if (!(choice[0] == '1' || choice[0] ==  '2' || choice[0] ==  '3')){
					printf("Not vaild\n\n");
				}
				else{
				inputValid = TRUE;
				}
			}
			*/
		}

		
		switch (choice[0])
		{
			/* play a game option */
			case '1' : 
				srand(time(NULL));
				if(get_human_player(&human_player)==FAILURE){
						printf("\n");
						break;
				}
				get_computer_player(&computer_player);
				random = rand() % 100 + 1;
				if( random > 50){
						human_player.thiscolor  = C_RED;
						computer_player.thiscolor = C_WHITE;
				}else{
					human_player.thiscolor = C_WHITE;
					computer_player.thiscolor=C_RED;
				}
				winner = play_game(&human_player,&computer_player);
				/* if there was not a draw, add player to the scoreboard in 
				 * order by number of tokens in play
				 */
				if (winner != NULL){
					/* let the user know who won */
					printf("\n %s has won the game\n ", (*winner).name);
					add_to_scoreboard(scores,winner);
					
				}else{
						/* if there was a draw, alert the user to this fact */
						if(computer_player.counters + human_player.counters == 42){
						printf("There has been a draw!");
						}
						
				}
				break;
				/* if there was a draw, alert the user to this fact */

			/* display the scoreboard option */
			case '2' :
				display_scores(scores);	
				break;

			/* quit the program option */
			case '3':
				isQuit = TRUE;
				return EXIT_SUCCESS;
				break;
		}
   
	}
	return EXIT_SUCCESS;
}
/*Clears terminal screen*/

