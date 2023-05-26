#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFSIZE 1024
extern char **environ;

/**
 * struct command - structure for built_in commands
 * @cmdname: Command name to be called.
 * @function: function performing the command task
 * Description: The structure contains the name of a function
 * to be called and a function pointer to the function to be called.
 */
typedef struct command
{
	char *cmdname;
	void (*function)(char *arg);
} built_in;

/**
 * struct command_s - the structure store a commmand and arguments
 * @command: command name or simply a command.
 * @argument: Array of arguments of the command.
 * @next: pointer to the next node.
 * Description: Every command and the arguments are craeted as a node
 * at each command call.
 */
typedef struct command_s
{
	char *command;
	char **argument;
	struct command_s *next;
} create_cmd;

void prompt(void);
char *_getenv(char *varname);
int remove_reading_space(char **buffer, char *line);
int _readline(char *line);
void (*func_ptr(char *str))(char *);
char *break_input_line(char *line, char *seperator);
char *_cmd_abs_path(char *cmdname);
void clean_token(char **tk_copy, char **token);
void process_args(char **command, char ***args, char *line_ptr, char *delim);
create_cmd *parse_cmd(create_cmd **head, char *line_ptr, char *delim);
void free_node(create_cmd **argv);
char *_strstr(char *mainstr, char *substr);

void execution_call(char *av);
void execute_path_command(create_cmd *argv, int n, char *av);
void handle_error(char *av, int n, char *cmdname);

void _ctrlC(int sig __attribute__((unused)));
void _exit_process(char *status, create_cmd **head);
void env(char *en __attribute__((unused)));

void print_number(int n);
int _putchar_errno(char c);
int _strlen(char *string);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
char *_strstr(char *mainstr, char *substr);
char *_strcpy(char *destination, char *source);
int _atoi(char *string);
int _putchar(char c);
void _puts(char *str);
char *_memset(char *s, char value, unsigned int num);

#endif
