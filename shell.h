/*************************** SHELL.H  *********/
#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*******************  main_shell.c  **********/

int main(int ac, char **av, char **env);
void handle(int signals);
void prompt(void);
void shell_exit(char **command);
void _EOF(char *buffer);

#endif
/** END _SHELL_H****/
