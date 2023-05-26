#include "simple_shell.h"

/**
 * func_ptr - looks any funtion matching str.
 * @str: input string to look for.
 * Return: pointer to a function that takes a string
 * argv as input and returns void
 *
*/

void (*func_ptr(char *str))(char *)
{
	int i = 0;

	built_in cmd[] = {
		{"env", env},
		{NULL, NULL}
	};

	while (cmd[i].cmdname != NULL)
	{
		if (_strcmp(cmd[i].cmdname, str) == 0)
		{
			return (cmd[i].function);
		}
		i++;
	}
	return (NULL);
}
