#include "simple_shell.h"

/**
 * prompt - displays a shell prompt.
 * Return: nothing.
*/
void prompt(void)
{
	write(1, "$ ", 2);
}
