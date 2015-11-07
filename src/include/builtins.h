/**
@file      src/include/builtins.h
@author    Bryce Davis
@date      6 November 2015
@brief     Builtin shell functions
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#ifndef _BSH_BUILTINS_H
#define _BSH_BUILTINS_H

int bsh_cd(char**);
int bsh_help(char**);
int bsh_exit(char**);

/**
@var static char** builtin_str
Array of string names of builtin functions
*/
static char* builtin_str[] = {
	"cd",
	"help",
	"exit"
};
/**
@var static int (**builtin_func)(char**)
Array of function pointers to builtin functions
*/
static int (*builtin_func[])(char**) = {
	&bsh_cd,
	&bsh_help,
	&bsh_exit
};
/**
@def NUM_BUILTINS
The number of builtin functions
*/
#define NUM_BUILTINS (int)(sizeof(builtin_str)/sizeof(char*))

#endif