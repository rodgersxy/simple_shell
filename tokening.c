#include "shell.h"

/**
 * tokening - function that splits and creates a full string command.
 * @s: a delimeter for strtok.
 * @buffer: pointer to input string.
 *
 * Return: string with command.
 */
char **tokening(char *buffer, const char *s)
{
	char *token = NULL;
	char **command = NULL;
	size_t bufsize = 0;
	int i = 0;


	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	command = malloc((bufsize + 1) * sizeof(char *));

	if (command == NULL)
	{
		perror("Can't locate buffer");
		free(buffer);
		free_dp(command);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token == NULL)
	{
		command[i] = malloc(_strlen(token) + 1);
		if (command[i] == NULL)
		{
			perror("Can't allocate buffer");
			free_dp(command);
			return (NULL);
		}
		_strcpy(command[i], token);
		token = strtok(NULL, s);
		i++;
	}

	command[i] = NULL;
	return (command);
}
