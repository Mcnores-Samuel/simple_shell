#include "simple_shell.h"

/**
 * _strncpy - copies n bytes of string src to dest.
 * @dest: pointer to string destination.
 * @src: pointer to string source.
 * @n: number of bytes to copy from src to dest.
 * Return: pointer to the destination string.
*/
char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		if (j < n)
		{
			dest[j] = src[j];
		}
	}

	for (; j < n; j++)
	{
		dest[j] = '\0';
	}

	return (dest);
}

/**
 * _strstr - finds the first occurrence of the substring in the main string.
 * @mainstr: pointer to the main string.
 * @substr: pointer to substring
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
*/
char *_strstr(char *mainstr, char *substr)
{
	int i = 0, j = 0;

	if (!*substr)
	{
		return (mainstr);
	}

	while (mainstr[i])
	{
		while (substr[j] && mainstr[i + j] == substr[j])
		{
			j++;
		}
		if (!substr[j])
		{
			return (mainstr + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/**
 * _strcpy - copy a string from source to destination
 * @destination: where the string is copied to
 * @source: where the string is copied from
 * Return: pointer to the destination
 *
 */

char *_strcpy(char *destination, char *source)
{

	while (*source != '\0')
	{
		*destination++ = *source++;
	}
	*destination = '\0';

	return (destination);
}

/**
 * _puts - function prints strings and prints a new line aftre
 * @str: pointer to strings of character
 *
 * Return: Void
 */

void _puts(char *str)
{
	char try;

	do {
		if (*str != '\0')
		{
			try = *str;
			_putchar(try);
		}
	} while (*str++);
	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
