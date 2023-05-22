#include "simple_shell.h"

/**
 * _readline - reads input from the command line.
 * @line: pointer to an array to hold the input line.
 * Return: number of bytes read or -1 on failure.
 */
int _readline(char *line)
{
	char character = '\0';
	size_t i = 0;
	int char_read;

	while (character != EOF && character != 10)
	{
		char_read = read(STDIN_FILENO, &character, 1);

		if (char_read == 0 || char_read < 0)
		{
			return (-1);
		}




		if (character != 10)
		{
			line[i] = character;
			i++;
		}
		else
		{
			break;
		}
	}
	line[i] = '\0';

	return (i);
}
