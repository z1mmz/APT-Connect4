/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : Wolf Zimmermann
* Student Number   : S3495671
* Course Code      : Cosc1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"

/**
 * @file game.c contains the functions that relate to the management of
 * the game.
 **/

/**
 valgrind* This requirement requires you to understand a little more about pointers.
 * We want you to understand that all pointers just point to another memory
 * address whether they are a single pointer, a pointer to a pointer, etc.
 * 
 * In this example, we want you to swap the pointers for two players. 
 * This will be called from \ref play_game with a call such as 
 * swap(&current, &other) and at the end of this function, current and
 * other's pointers will be swapped.
 * For example, if current points to the human player and other points to 
 * the computer player, at the end of this function, the player they point 
 * to will have been swapped. 
 * 
 * @param current the current player who has just completed their turn
 * @param other the next player whose turn it will be
 **/
static void swap_players(struct player ** current, struct player ** other)
{
    /* implement a classic swap using a temporary pointer */
    struct player *temp = *current;
    *current = *other;
    *other = temp;
}

/**
 * This is the heart of the game.
 * 
 * Firstly, you need to initialise the game by calling functions written 
 * for requirement 3. The rest of this function is then managing the game 
 * loop.
 *
 * Each player takes a turn to drop a token into a column on the game 
 * board. The task that needs to be performed will be different depending 
 * on whether this is a human or a computer player.
 *
 * Regardless of the player type, you will need to display the board as it 
 * was before the player makes their move. If the current player is a 
 * computer player, we just need to select a column at random and drop a
 * token into that column. If there is no room, try another column.
 *
 * If the current player is a human player, your program will need to ask 
 * the user what column they wish to drop a token in. This input should be 
 * validated to check that it is numeric and within the range of allowed 
 * columns.
 * 
 * Once a valid move has been entered, your program should update the 
 * gameboard. It should then check if the game has been won lost or drawn 
 * by calling and the change the current player.
 *
 * This function also checks if the game has been won, lost or drawn by 
 * calling \ref test_for_winner(), and if the game is over, returns the 
 * winner to main or NULL if the game was a draw.

 * @param human a pointer to details about the human player
 * @param computer a pointer to details about the computer player
 **/
struct player * play_game(struct player * human , 
        struct player* computer)
{	
	int x = 0;
	struct player *current, *other;
	enum game_state currentState;
    /* declaration that allocates the board for the game */
    enum cell_contents board[BOARDHEIGHT][BOARDWIDTH];
	initialise_board(board);
	if((*human).thiscolor == C_WHITE){
	current = human;
	other = computer;
	}else{
	current = computer;
	other = human;
	}
	
	while(x==0){
	display_board(board);
	 if(take_turn(current,board)==RTM){
			return NULL;
			
	 }
	currentState = test_for_winner(board);
	if(currentState == G_NO_WINNER){
	swap_players(&current,&other);
	}else{
		x = 1;
	}

	}
	
	if(currentState == G_RED){
		display_board(board);
		if((*human).thiscolor == C_RED){
		return human;
			}if((*computer).thiscolor == C_RED){
			return computer;
		}
		
		
	}
	if(currentState == G_WHITE){
		display_board(board);
		if((*human).thiscolor == C_WHITE){
			return human;
			}
			if((*computer).thiscolor == C_WHITE){
			return computer;
			}
		
	}
	if(currentState == G_DRAW){
		display_board(board);
		return NULL;

	}
    return NULL;
}

/**
 * In this requirement you are required to test what the game's current 
 * state is.
 * Possible game states are defined by the game_state enumeration:
 * enum game_state
 * {
 *    G_NO_WINNER=-1,
 *    G_DRAW,
 *    G_RED,
 *    G_WHITE
 * };
 *
 * Most of these states should be self-explanatory but let's go through 
 * their meaning.
 * 
 *    &bull; G_NO_WINNER: the game is still in progress and therefore there
 *    is no winner yet.
 * 
 *    &bull; G_DRAW: neither player has won the game but there are no more 
 *    spaces left for a player to make a move.
 *    
 *    &bull; G_RED / G_WHITE: the player whose token is the specified 
 *    colour has won the game.
 *
 * Your task in this function is to iterate over the 2-dimensional array 
 * (the board) looking for four in a row in any direction – if you find 
 * this, return the appropriate value of either G_RED or G_WHITE.
 *
 * Next, test for a draw. If none of these cases hold, return G_NO_WINNER.
 * @param board the gameboard to test for a winner
 **/
enum game_state test_for_winner(
        enum cell_contents board[][BOARDWIDTH])
	{
		int white =0,red = 0;
		int x,i,z,y;
			/* THE NEW CHECK!*/
			for(x = BOARDHEIGHT; x >= 0 ; x--){
					for( i = 0; i < BOARDWIDTH; i++){
						white = 0;
						red = 0;
						
						for(z=0 ; z <= 4 ; z++){
								/*check vert downwards*/
								if (x+z <= BOARDHEIGHT){
									if (board[x+z][i] == C_RED){
											red++;
											white = 0;
									}
									if(red == 4){
											return G_RED;
									}
									if (board[x+z][i] == C_WHITE){
										white++;
										red = 0;
									}
									if(white == 4){
										return G_WHITE;
									}
									if (board[x+z][i] == C_EMPTY){
										white = 0;
										red = 0;
									}
									
								}
								}
					
									
								
					
								
							white = 0;
							red = 0;
							/*CHECK TO THE RIGHT*/
							for(z=0 ; z <= 4 ; z++){
								if (i+z < BOARDWIDTH){
									if (board[x][i+z] == C_RED){
										red++;
										white = 0;
									}
									if(red == 4){
										return G_RED;
									}
									if (board[x][i+z] == C_WHITE){
										white++;
										red = 0;
									}
									if(white == 4){
										return G_WHITE;
									}
									if (board[x][i+z] == C_EMPTY){
										white = 0;
										red = 0;
									}
								}
								
							}
							white = 0;
							red = 0;
							/*Check to the left*/
							for(z=0 ; z <= 4 ; z++){
								if (i-z >= 0){
									if (board[x][i-z] == C_RED){
										red++;
										white = 0;
									}
									if(red == 4){
										return G_RED;
									}
									if (board[x][i-z] == C_WHITE){
										white++;
										red = 0;
									}
									if(white == 4){
										return G_WHITE;
									}
									if (board[x][i-z] == C_EMPTY){
										white = 0;
										red = 0;
									}
									
								}							
				
							}
							/*Check diag to right */
							white = 0;
							red = 0;
							for(z=0 ; z <= 4 ; z++){
								if (i+z < BOARDWIDTH && x+z <= BOARDHEIGHT){
									if (board[x+z][i+z] == C_RED){
										red++;
										white = 0;
									}
									if(red == 4){
										return G_RED;
									}
									if (board[x+z][i+z] == C_WHITE){
										white++;
										red = 0;
									}
									if(white == 4){
										return G_WHITE;
									}
									if (board[x+z][i+z] == C_EMPTY){
										white = 0;
										red = 0;
									}
									
								}							
				
							}
							/*Check diag to left*/
							white = 0;
							red = 0;
							for(z=0 ; z <= 4 ; z++){
								if (i-z >= 0 && x+z <= BOARDHEIGHT){
									if (board[x+z][i-z] == C_RED){
										red++;
										white = 0;
									}
									if(red == 4){
										return G_RED;
									}
									if (board[x+z][i-z] == C_WHITE){
										white++;
										red = 0;
									}
									if(white == 4){
										return G_WHITE;
									}
									if (board[x+z][i-z] == C_EMPTY){
										white = 0;
										red = 0;
									}
									
								}							
				
							}
							
				
			}
		}
		
		for(y = BOARDHEIGHT - 1; y >= 0 ; y--){
			for(x = 0; x < BOARDWIDTH; x++){
				if(board[y][x] == C_EMPTY){
					return G_NO_WINNER;
				}
			}
		}
    return G_DRAW;
}

