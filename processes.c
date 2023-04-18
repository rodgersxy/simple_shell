#include "shell.h"
/**
 * create_child - The function is responsible for creatring child
 * process to execute command entered in the terminal
 * @command: THe pointer that represents commands to be executed
 * @env: The pointer to the enviroment variables
 * @name: Pointer that represents commands to be executed.
 * @max_executions: integer representing number of circles shell will run
 * Return: Nothing
 */
void create_child(char **command, char *name, char **env, int max_executions)
{
	/*pid_t(datatype) will store the processs ID*/
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error: ");
		free_exit(command);
	}

	else if (pid == 0)
	{
		execute(command, name, env, max_executions);
		free_dp(command);
		_exit(EXIT_FAILURE);
	}
	else
	{
		do {
			/*WUNTRACED flag for suspending processes*/
			if (waitpid(pid, &status, WUNTRACED) == -1)
			{
				perror("waitpid");
				free_exit(command);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

		free_dp(command);
	}
}
