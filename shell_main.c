#include "simple_shell.h"

/**
 * execute_path_command - executes a command given by the user.
 * @argv: a pointer to a create_cmd struct as an argument.
 * @n: number to indicate processes created by the shell or
 * it indicates how many commands executed.
 * @av: The name of the executable file.
 * Return: nothing
*/
void execute_path_command(create_cmd *argv, int n, char *av)
{
	pid_t child;
	char *command = NULL;
	int status;

	command = _cmd_abs_path(argv->command);

	if (command != NULL)
	{
		if (argv->command != command)
		{
			free(argv->command);
			argv->command = command;
			argv->argument[0] = command;
		}

		child = fork();

		if (child == 0)
		{

			if (execve(argv->command, argv->argument, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child, &status, 0);
		}
	}
	else
	{
		handle_error(av, n, argv->command);
	}
}

/**
 * execution_call - calls for the execution of a command.
 * @av: pointer to the name of the executable shell file.
 * Return: nothing.
 */
void execution_call(char *av)
{
	char ptr_line[1024];
	create_cmd *argv = NULL;
	void (*built_in_func)(char *);
	char *delim = " ";
	int n_byte;
	static int process_count;

	n_byte = _readline(ptr_line);
	if (n_byte == -1)
	{
		exit(0);
	}

	if (n_byte > 0)
	{
		parse_cmd(&argv, ptr_line, delim);

		built_in_func = func_ptr(argv->command);

		process_count++;

		if (_strcmp(argv->command, "exit") == 0)
		{
			_exit_process(argv->argument[1], &argv);
		}

		if (built_in_func != NULL)
		{
			built_in_func(argv->argument[1]);
			free_node(&argv);
		}
		else
		{
			execute_path_command(argv, process_count, av);
			free_node(&argv);
		}
	}
}

/**
 * main - The shell's entry point and waits for user input.
 * @ac: argument count(unused)
 * @av: array of commandline arguments.
 * Return: exit with success signal unless interrupted.
 */
int main(int ac __attribute__((unused)), char **av)
{
	if (isatty(STDIN_FILENO))
	{
		do {
			signal(SIGINT, _ctrlC);
			prompt();
			execution_call(av[0]);
		} while (1);
	}
	else
	{
		do {
			execution_call(av[0]);
		} while (1);
	}
	exit(errno);
}
