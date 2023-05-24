#include "simple_shell.h"

/**
 * _readline - reads input from the command line.
 * @line: pointer to an array to hold the input line.
 * Return: number of bytes read or -1 on failure.
 */
int _readline(char *line)
{
	char character = '\0', *buffer;
	int i = 0, n;
	int char_read, size = 10;

	buffer = (char *)malloc(sizeof(char) * size);
	while (character != EOF && character != 10)
	{
		char_read = read(STDIN_FILENO, &character, 1);

		if (char_read == 0 || char_read < 0)
		{
			return (-1);
		}

		if (i >= size)
		{
			size += 5;
			buffer = realloc(buffer, size);
		}

		if (character != 10)
		{
			buffer[i] = character;
			i++;
		}
		else
		{
			break;
		}
	}
	buffer[i] = '\0';

	for (i = 0; i < _strlen(buffer); i++)
		if (buffer[i] != ' ')
			break;

	for (n = 0; buffer[i] != '\0'; n++)
	{
		line[n] = buffer[i];
		i++;
	}
	free(buffer);
	line[n] = '\0';
	return (i);
}
