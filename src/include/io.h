/**
@file      src/include/bsh.h
@author    Bryce Davis
@date      6 November 2015
@brief     I/O utilities for the shell
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. 
					 See the LICENSE.txt file for details.
*/
#ifndef _BSH_IO_H
#define _BSH_IO_H

extern char* bsh_read_line(void);
extern char** bsh_split_line(char*);

#endif