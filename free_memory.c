#include "shell.h"
/**
 * free_dp - A fuction designed to free memory allocated for a dynamically
 * allocated array of strings
 * @command: Pointer to allocated memory to free
 *
 * Return: Nothing.
 */
void free_dp(char **command)
{
	/*initialize size_t variable 'i' to 0*/
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);

	free(command);
}
