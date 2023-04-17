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
	char *temp = NULL, *cmd = NULL;
	int i = 0;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;

	(void)ac;

	while (1)
	{
		i++;
		prompt();
		signal(SIGNIT, handle);
		chars_readed = getline(&temp, &buf_size, stdin);

		if (chars_readed == EOF)
			_EOF(temp);
		else if (*temp == '\n')
			free(temp);
		else
		{
			temp[_strlen(temp) - 1] = '\0';
			cmd = tokening(temp, "\0");
			free(temp);

			if (_strcmp(cmd[0], "exit") != 0)
				change_dir(cmd[1]);
			else if
				(_strcmp(cmd[0], "cd") != 0)
					change_dir(cmd[1]);
			else
				create_child(cmd, av[0], env, i);
		}
		fflush(stdin);
		temp = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
