#include "simple_shell.h"

/**
 * clean_token - filters a token and copy the filtered token to tk_copy.
 * if filters a newline and null terminating character from a token.
 * @tk_copy: pointer to pointer to the filtered token.
 * @token: pointer to pointer to the token to filter.
 * Return: void/nothing.
*/
void clean_token(char **tk_copy, char **token)
{
	int len = 0;

	while ((*token)[len] != 10 && (*token)[len] != '\0')
	{
		len++;
	}

	*tk_copy = (char *)malloc(sizeof(char) * (len + 1));
	_strncpy(*tk_copy, *token, len);
	(*tk_copy)[len] = '\0';
}

/**
 * process_args - processes the arguments by allocating memory for every
 * command and all its arguments.
 * @command: double pointer to a command.
 * @args: pointer to pointer to pointer to array of arguments.
 * @line_ptr: pointer to input line to craete command and arguments from.
 * @delim: pointer to separator for the line to indivudual worlds.
 * Return: nothing.
*/
void process_args(char **command, char ***args, char *line_ptr, char *delim)
{
	char *token;
	int arg_count = 1;
	char *cpy_token;

	*args = (char **)malloc(sizeof(char *) * 20);
	if (*args == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = break_input_line(line_ptr, delim);

	while (token != NULL && arg_count < 20)
	{
		if (*command == NULL)
		{
			clean_token(&cpy_token, &token);
			*command = cpy_token;
			(*args)[0] = cpy_token;
		}
		else
		{
			clean_token(&cpy_token, &token);
			(*args)[arg_count++] = cpy_token;
		}
		token = break_input_line(NULL, delim);
	}

	(*args)[arg_count] = NULL;
}

/**
 * parse_cmd - breaks down a input line into individual strings.
 * and creates a node.
 * @head: pointer to head node.
 * @line_ptr: pointer to the input line.
 * @delim: pointer to the separator
 * Return: node created.
*/
create_cmd *parse_cmd(create_cmd **head, char *line_ptr, char *delim)
{
	create_cmd *new_node = NULL;
	int i = 1;

	if (*line_ptr == '\0' || line_ptr == NULL)
		return (NULL);

	new_node = (create_cmd *)malloc(sizeof(create_cmd));

	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->command = NULL;
	new_node->argument = NULL;

	if (*head == NULL)
	{
		process_args(&(new_node->command), &(new_node->argument), line_ptr, delim);
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	else
	{
		free((*head)->command);
		(*head)->command = NULL;
		while ((*head)->argument[i] != NULL)
		{
			free((*head)->argument[i]);
			i++;
		}
		free(((*head)->argument));
		(*head)->argument = NULL;
		free(*head);
		*head = NULL;
		process_args(&(new_node->command), &(new_node->argument), line_ptr, delim);
		new_node->next = *head;
		*head = new_node;
	}
	return (new_node);
}
