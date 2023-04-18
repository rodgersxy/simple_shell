#include "shell.h"

/**
 * main - the main function of the project that runs the shell.
 * @ac: number of arguments put.
 * @av: pointer to array of input arguments.
 * @env: pointer to pointer to array of environmental variables.
 *
 * Return: Always(0)
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *command = NULL;
	int i = 0;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;

	(void)ac;

	while (1)
	{
		i++;
		prompt();
		signal(SIGINT, handle);
		chars_readed = getline(&buffer, &buf_size, stdin);

		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, "\0");
			free(buffer);

			if (_strcmp(command[0], "exit") != 0)
				change_dir(command[1]);
			else if
				(_strcmp(command[0], "cd") != 0)
					change_dir(command[1]);
			else
				create_child(command, av[0], env, i);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
