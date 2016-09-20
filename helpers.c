/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1 
* Full Name        : Wolf Zimmermann
* Student Number   : S3495671
* Course Code      : Cosc1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "helpers.h"

/**
 * @file helpers.c contains various functions that help in the
 * implementation of the program. You should put functions you create
 * here unless they logically belong to another module (such as
 * player, board or game
 **/

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch!=EOF && ch != '\n')
        ; /* gobble each character */
    /* reset the error status of the stream */
    clearerr(stdin);
}
enum input_result get_Input(char *write){
		int Slen;

	if(fgets(write,sizeof(write) + 2 ,stdin) == NULL){

	return RTM;
	}
	if(write[strlen(write) - 1] != '\n'){
	
		printf("\n %s", write);
		
		return FAILURE;
	}else
	{	Slen = strlen(write);
		if(write[Slen - 1] == '\n'){
			write[Slen - 1] = '\0';

			return SUCCESS;
		}
	}
	return FAILURE;
}



