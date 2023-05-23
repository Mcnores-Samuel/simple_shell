#include "simple_shell.h"

/**
 * _readline - reads input from the command line.
 * @line: pointer to an array to hold the input line.
 * Return: number of bytes read or -1 on failure.
 */
int _readline(char *line)
{
	char characters[1024];
	int i = 0, n = 0;
	int char_read;
	
	char_read = read(STDIN_FILENO, &characters, 1024);
	if (char_read == 0 && char_read < 0)
		return (-1);
	characters[char_read] = '\0';

	for (i = 0; i < _strlen(characters); i++)
		if (characters[i] != ' ')
			break;

	while (characters[i] != 10)
	{
		if (characters[i] == EOF)
			return (-1);
		if (characters[i] != 10)
		{
			line[n] = characters[i];
			i++;
			n++;
		}
		else
		{
			break;
		}
	}
	line[i] = '\0';

	return (i);
}
