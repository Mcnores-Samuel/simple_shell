#include "simple_shell.h"

/**
 * _ctrlC - handles user interrupt signal.
 * @sig: unused.
 * Return: void.
*/
void _ctrlC(int sig __attribute__((unused)))
{
	_putchar('\n');
	prompt();
}
