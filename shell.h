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

int _putchar(char c);



/*********************  PROCESSES   *****/

int change_dir(const char *path);
void create_child(char **command, char *name, char **env, int max_executions);

/****************** TOKENING ***************/

char **tokening(char *buffer, const char *s);

/*******************STRING_FUNCTIONS************/

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _atoi(char *s);

/************** EXCECUTE *********************/

void execute(char **command, char *name, char **env, int cc);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cc, char **command);

/********************FREE_MEMORY******/

void free_dp(char **command);
void free_exit(char **command);

#endif   /** END _SHELL_H****/
