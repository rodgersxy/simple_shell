#include "shell.h"
/**
 * change_dir - The function changes the working directory to a
 * given PATH.
 * @path: Current working directory
 *
 * Return: 0 if successful else -1.
 */
int change_dir(const char *path)
{
	/*declare a null pointer to char and a variable size*/
	size_t size = 1024;
	char *buff = NULL;

	if (path == NULL)
		path = getcwd(buff, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}

	return (1);
}
