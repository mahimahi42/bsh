/**
@file      src/include/global.h
@author    Bryce Davis
@date      6 November 2015
@brief     Global includes and definitions
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#ifndef _BSH_GLOBAL_H
#define _BSH_GLOBAL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
#def UNUSED(x)
Macro to suppress unused parameter warnings
*/
#define UNUSED(x) (void)(x)

/**

*/
#define UNUSED_VAR(x) do { (void)(x); } while (0);

#endif