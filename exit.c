#include "simple_shell.h"

/**
 * _exit_process - terminates the normal process of the shell.
 * @status: exit status number.
 * @head: double to the node to free.
 * Return: nothing.
*/
void _exit_process(char *status, create_cmd **head)
{
	char cpy_status[100];
	int status_no = 0;

	if (status != NULL)
	{
		strcpy(cpy_status, status);
		status_no = _atoi(cpy_status);
	}

	if (status_no < 0)
	{
		free_node(head);
		exit(errno);
	}
	else if (status_no > 0)
	{
		free_node(head);
		exit(status_no);
	}
	else
	{
		free_node(head);
		exit(errno);
	}
}

