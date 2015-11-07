/**
@file      src/include/bsh.h
@author    Bryce Davis
@date      6 November 2015
@brief     A simple toy shell written in C
					 It can change directories, display a help menu, and exit!
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#ifndef _BSH_H
#define _BSH_H

/**
@def DEFAULT_BSH_PROMPT
The default bsh prompt
*/
#define DEFAULT_BSH_PROMPT "bsh> "

int main(int, char**);
int bsh_launch(char**);
int bsh_execute(char**);
void bsh_loop(void);

#endif
