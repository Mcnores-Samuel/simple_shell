#include "simple_shell.h"

/**
 * _exit_process - terminates the normal process of the shell.
 * @status: exit status number.
 * Return: nothing.
*/
void _exit_process(char *status)
{
	if (status != NULL)
	{
		exit(_atoi(status));
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

