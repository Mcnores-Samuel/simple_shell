#include "simple_shell.h"

/**
 * _strlen - calculates the string length.
 * @string: the string.
 * Return: number bytes or character in the string.
*/
int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - compares two strings.
 * @str1: first string to compare
 * @str2: second string to compare with.
 * Return: 0 on success or any other number on failure.
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0')
	{
		i++;
	}

	if (str1[i] == str2[i])
	{
		return (str1[i] - str2[i]);
	}
	else
	{
		return (str1[i] - str2[i]);
	}
}

/**
 * _strncmp - compares specified number of bytes in two strings.
 * @str1: first string.
 * @str2: second string.
 * @n: number of bytes to compare.
 * Return: 0 on success or random number on failure.
*/
int _strncmp(const char *str1, const char *str2, int n)
{
	int i = 0;

	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}

	if (i == n)
	{
		return (0);
	}
	else
	{
		return (str1[i] - str2[i]);
	}
}

/**
 * _strcat - appends a string at the end of another string.
 * @dest: The string to append to.
 * @src: source string to be appended.
 * Return: pointer to resulting string dest.
*/
char *_strcat(char *dest, char *src)
{
	int len = strlen(dest), i = 0;

	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string.
 * @str: string to duplicate.
 * Return: pointer to the duplicate string.
*/
char *_strdup(char *str)
{
	char *dest;
	int len = 0, i = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	dest = (char *)malloc(sizeof(char) * (len + 1));

	if (dest == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
