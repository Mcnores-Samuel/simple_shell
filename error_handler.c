#include "simple_shell.h"

/**
 * handle_error - sends error message to standard error.
 * @av: pointer to the name of the calling program.
 * @n: number of the processes or calling processes
 * @cmdname: pointer to the name of the command.
 * Return: void.
 */
void handle_error(char *av, int n, char *cmdname)
{
	char str[] = ": not found\n";

	write(2, av, _strlen(av));
	write(2, ": ", 2);
	print_number(n);
	write(2, ": ", 2);
	write(2, cmdname, _strlen(cmdname));
	write(2, &str, _strlen(str));
}


/**
 * print_number - prints an integer.
 * @n: integer to print.
 * Return: void
 */

void print_number(int n)
{
	unsigned int k = n;

	if (n < 0)
	{
		n *= -1;
		k = n;
		_putchar_errno('-');
	}

	k /= 10;

	if (k != 0)
		print_number(k);

	_putchar_errno((unsigned int) n % 10 + '0');

}

/**
 * _putchar_errno - prints a character to the standard error
 * @character: a character to print.
 * Return: number of characters written.
 */
int _putchar_errno(char character)
{
	return (write(2, &character, 1));
}

