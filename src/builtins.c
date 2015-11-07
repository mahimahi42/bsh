/**
@file      src/builtins.c
@author    Bryce Davis
@date      6 November 2015
@brief     Builtin shell functions
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#include "global.h"
#include "builtins.h"

/**
@fn bsh_cd(char** args)
@brief Change the current directory
@param args List of args. args[0] is the name of the program
@return 1 on success
*/
int bsh_cd(char** args)
{
	// No argument to cd results in an error
	if (args[1] == NULL) {
		fprintf(stderr, "bsh: expected argument to \"cd\"\n");
	} else {
		// If chdir() isn't successful, let's let the user know it's our fault :(
		if (chdir(args[1]) != 0) {
			perror("bsh");
		}
	}
	return 1;
}

/**
@fn bsh_help(char** args)
@brief Print a help screen
@param args List of args. args[0] is the name of the program
@return 1 on success
*/
int bsh_help(char** args)
{
	UNUSED(args);
	printf("Bryce Davis' BSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are builtin:\n");

	for (int i = 0; i < NUM_BUILTINS; i++) {
		printf("\t%s\n", builtin_str[i]);
	}

	printf("Use the man command for info on other programs.\n");
	return 1;
}

/**
@fn bsh_exit(char** args)
@brief Exit the current process
@param args List of args. args[0] is the name of the program
@return 0 on success
*/
int bsh_exit(char** args)
{
	UNUSED(builtin_func); // To suppress compiler warning
	UNUSED(args);
	return 0;
}