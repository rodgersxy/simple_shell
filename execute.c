#include "shell.h"

/**
 * execute - Function that's responsible for command execution
 * @command: pointer to tokenized command.
 * @name: name of the shell.
 * @env: pointerto the environmental variables
 * @cc: number of executed cycles.
 *
 * Return: void.
 */
void execute(char **command, char *name, char **env, int cc)
{
	char **pathways = NULL;
	char *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}

	else
	{
		pathways = _getPATH(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_dp(pathways);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, cc, command);
		free_dp(pathways);
	}
}



/**
 * print_env - Function that prints all environmental variables.
 * @env: Pointer to environmental variables.
 * Return: nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}


/**
 * _getPATH - a function that gets the full value from environmental
 * variable PATH.
 * @env: The pointer to environmental variables.
 *
 * Return: All tokenized pathways for commands.
 */
char **_getPATH(char **env)
{
	char *pathvalue = NULL;
	char **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokening(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}


/**
 * msgerror - Function that prints a message that can't be found.
 * @name: The name of the shell.
 * @cc: Number of cycles.
 * @command: number of tokenized commands.
 * Return: Nothing.
 */
void msgerror(char *name, int cc, char **command)
{
	char c;

	c = cc + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": " 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
