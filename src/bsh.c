/**
@file      src/bsh.c
@author    Bryce Davis
@date      6 November 2015
@brief     A simple toy shell written in C
					 It can change directories, display a help menu, and exit!
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#include "bsh.h"

#include <stdlib.h>

/**

*/
int main(int argc, char** argv)
{
	// Load any configuration files

	// Run the command loop
	bsh_loop();

	// Perform any shutdown/cleanup

	return EXIT_SUCCESS;
}