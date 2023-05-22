#include "simple_shell.h"

/**
 * env - displays the shell environment.
 * @en: unused.
 * Return: nothing
*/
void env(char *en __attribute__((unused)))
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		i++;
	}
}

