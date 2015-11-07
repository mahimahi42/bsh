/**
@file      src/bsh.c
@author    Bryce Davis
@date      6 November 2015
@brief     A simple toy shell written in C
					 It can change directories, display a help menu, and exit!
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "bsh.h"
#include "io.h"

/**
@fn int main(int argc, char** argv)
@brief Begin the command processing loop
@param argc the number of command line arguments
@param argv a char array of the cmd line args
@return EXIT_SUCCESS for good style!
*/
int main(int argc, char** argv)
{
	// Load any configuration files

	// Run the command loop
	bsh_loop();

	// Perform any shutdown/cleanup

	return EXIT_SUCCESS;
}

/**
@fn void bsh_loop()
@brief Repeatedly prompt for a command until user exits
*/
void bsh_loop(void)
{
	char*  line;		///< The current line input by the user
	char** args;		///< The arguments to the command
	int    status;  ///< The last process' status

	do {
		printf(DEFAULT_BSH_PROMPT);
		
	} while (status);
}