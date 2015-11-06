@file src/include/bsh.h
@author Bryce Davis
@date 6 November 2015
@brief A simple toy shell written in C
@copyright Copyright (c) 2015 Bryce Davis. Released under the MIT License. See the LICENSE.txt file for details.
#ifndef _BSH_H
#define _BSH_H

int main(int, char**);
int bsh_launch(char**);
int bsh_execute(char**);
char* bsh_read_line(void);
char** bsh_split_line(char*);
void bsh_loop(void);

#endif