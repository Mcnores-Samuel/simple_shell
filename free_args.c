#include "simple_shell.h"

/**
 * free_node - releases memory location held by argv node.
 * @argv: pointer to pointer to a node to free.
 * Return: void;
 *
 */
void free_node(create_cmd **argv)
{
	size_t index = 1;

	free((*argv)->command);
	while ((*argv)->argument[index] != NULL)
	{
		free((*argv)->argument[index]);
		index++;
	}
	free((*argv)->argument);

	free(*argv);
	*argv = NULL;
}
