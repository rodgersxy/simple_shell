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

/**
 * _strlen - This a function that finds the length of the string
 * @s: THe input string
 *
 * Return: String's length
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}


/**
 * _strcat - This is a function that concatenates into two strings
 * @src: An input pointer to string
 * @dest: string pointer
 *
 * Return: A pointer to the start of concatenated string
 */
char *_strcat(char *dest, char *src)
{
	/*declares a new pointer tmp ans set it to dest*/
	char *tmp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';

	while (*src)
		*dest++ = *src++;

	return (tmp);
}


/**
 * _atoi - This a function that converts strings into integers
 * @s: An input string pointer.
 *
 * Return: An integer value after it is converted
 */
int _atoi(char *s)
{
	unsigned int total = 0;
	int sign = 1;
	char is_number_found = 0;

	/*checks if the pointer is NULL*/
	if (s == NULL)
		return (0);

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			is_number_found = 1;
			total = total * 10 + (*s - '0');
		}

		else if (*s < '0' || *s > '9')
		{
			if (is_number_found == 1)
				break;
		}
		s++;
	}

	if (sign < 0)
		total = (-1 * (total));

	return (total);
}
