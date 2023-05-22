#include "simple_shell.h"

/**
 * _atoi - return an integer found in the string.
 * @string: string to search.
 * Return: converted integer from string.
 */
int _atoi(char *string)
{
	unsigned int i = 0, lenght = 0, init = 0, finish = 0;
	unsigned int num = 1, d = 0, sign = 0, sum = 0;

	lenght = _strlen(string);
	if (lenght == 0)
		return (0);
	for (i = 0; i < lenght; i++)
	{
		if (string[i] == '-')
			sign++;
		if (string[i] >= 48 && string[i] <= 57)
		{
			init = i;
			break;
		}
	}
	for (; i < lenght; i++)
		if (string[i] < 48 || string[i] > 57)
			break;
	finish = i - 1;
	for (; init <= finish; init++)
	{
		d = string[init] - '0';
		num = 1;
		for (i = 0; i < finish - init; i++)
			num = num * 10;
		num = num * d;
		sum = num + sum;
	}
	if (sign % 2 == 1)
		sum = sum * -1;
	return (sum);
}

