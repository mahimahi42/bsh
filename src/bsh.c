/**
@file      src/bsh.c
@author    Bryce Davis
@date      6 November 2015
@brief     A simple toy shell written in C
					 It can change directories, display a help menu, and exit! This shell
					 started as an implementation of a wonderful tutorial by Stephen
					 Brennan.
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "bsh.h"
#include "io.h"

/**
@fn int main(int argc, char** argv)
@brief Begin the command processing loop
@param argc The number of command line arguments
@param argv A char array of the cmd line args
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
	char*  line;		// The current line input by the user
	char** args;		// The arguments to the command
	int    status;  // The last process' status

	do {
		printf(DEFAULT_BSH_PROMPT);
		line   = bsh_read_line();
		args   = bsh_split_line(line);
		status = bsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

int bsh_launch(char** args)
{
	// PIDs for our use
	pid_t pid;
	// Process status
	int sts;

	pid = fork();
	if (pid == 0) {
		// We are the child process
		// If exec returns an error, we let the user know what the error is, and
		// that we caused it :(
		if (execvp(args[0], args) == -1) {
			perror("bsh");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		// There was an error forking
		// We let the user know what the error is, and that we caused it :(
		perror("bsh");
	} else {
		// We are the parent process
		do {
			waitpid(pid, &sts, WUNTRACED);
		} while (!WIFEXITED(sts) && !WIFSIGNALED(sts));
	}

	return 1;
}

int bsh_execute(char** args)
{


	return bsh_launch(args);
}