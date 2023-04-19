#include "shell.h"
/**
 * _strcmp - This a function that compares two strings
 * @s1: string one.
 * @s2: string 2
 *
 * Return: 1 if the string to compare is equal, otherwise 0.
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i;

	/*for loop to compare strings*/
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}

	return (1);
}

/**
 * _strcpy - A function that copies a string to another string
 * @src: Apointer to string to copy from
 * @dest: A pointer to the copied string
 *
 * Return: A pointer copied atring(results).
 */
char *_strcpy(char *dest, char *src)
{
	char *results = dest;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';
	return (results);
}
