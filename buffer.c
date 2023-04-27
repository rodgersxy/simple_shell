#include "shell.h"

/**
 * prompt - a function that prints the prompt
 *
 * Return: void.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "My_Shell$ ", 10);
}

/**
 * handle - a function that handles CTRL + C signal.
 * @signals: signal to handle.
 * Return: void.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nMy_Shell>> ", 12);
}

/**
 * _EOF - function that checks if temp is EOF
 * @temp: pointer to the input string.
 * Return: void.
 */
void _EOF(char *temp)
{
	if (temp)
	{
		free(temp);
		temp = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	exit(EXIT_SUCCESS);
}


/**
 * shell_exit - function that exits the shell.
 * @cmd: The pointer to tokenized command.
 * Return: Nothing.
 */
void shell_exit(char **cmd)
{
	int sta_tus = 0;
	char *endptr;

	if (cmd[1] == NULL)
	{
		free_dp(cmd);
		exit(EXIT_SUCCESS);
	}

	sta_tus = (int) strtol(cmd[1], &endptr, 10);

	if (*endptr != '\0') /*conversion failed*/
	{
		fprintf(stderr, "Error: %s is not a valid integer\n", cmd[1]);
		free_dp(cmd);
		exit(EXIT_FAILURE);
	}

	free_dp(cmd);
	exit(sta_tus);
}


