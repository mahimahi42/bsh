/**
@file      src/io.c
@author    Bryce Davis
@date      6 November 2015
@brief     I/O utilities for the shell
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#define _GNU_SOURCE
#include "global.h"
#include "io.h"

/**
@fn char* bsh_read_line(void)
@brief Reads a line from stdin
@return A char buffer containing the input line
*/
char* bsh_read_line(void)
{
	char* line = NULL;
	size_t bufsize = 0;
	getline(&line, &bufsize, stdin);
	return line;
}

/**
@fn char** bsh_split_line(char* line)
@brief Splits an input line into individual tokens
@param line The input line
@return The input line as an array of individual tokens
*/
char** bsh_split_line(char* line)
{
	size_t bufsize = BSH_TOK_BUF_SIZE;
	int pos = 0;

	char** tokens = malloc(bufsize * sizeof(char*));
	char* curr_tok;

	if (!tokens) {
		fprintf(stderr, "bsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	curr_tok = strtok(line, BSH_TOK_DELIM);
	while (curr_tok != NULL) {
		tokens[pos] = curr_tok;
		pos++;

		if ((size_t) pos >= bufsize) {
			bufsize <<= 1;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) {
				fprintf(stderr, "bsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		curr_tok = strtok(NULL, BSH_TOK_DELIM);
	}
	tokens[pos] = NULL;
	return tokens;
}