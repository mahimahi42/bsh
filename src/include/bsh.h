#ifndef _BSH_H
#define _BSH_H

int main(int, char**);
int bsh_launch(char**);
int bsh_execute(char**);
char* bsh_read_line(void);
char** bsh_split_line(char*);
void bsh_loop(void);

#endif