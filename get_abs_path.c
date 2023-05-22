#include "simple_shell.h"

/**
 * _cmd_abs_path - creates absolute absolute path for command and
 * test if the file path is executable.
 * @cmdname: pointer to the command to create absolute path for.
 * Return: executable absolute path.
*/
char *_cmd_abs_path(char *cmdname)
{
	char *pathname, *path, *copy_path, *path_ptr;
	int len;

	if (cmdname == NULL)
		return (NULL);
	if (access(cmdname, X_OK) == 0)
		return (cmdname);
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	copy_path = _strdup(path);
	path_ptr = break_input_line(copy_path, ":");
	while (path_ptr != NULL)
	{
		len = _strlen(path_ptr) + _strlen(cmdname) + 2;
		pathname = (char *)malloc(sizeof(char) * len);
		if (pathname == NULL)
		{
			free(copy_path);
			return (NULL);
		}
		_strcpy(pathname, path_ptr);
		_strcat(pathname, "/");
		_strcat(pathname, cmdname);
		_strcat(pathname, "\0");
		if (access(pathname, X_OK) == 0)
		{
			free(copy_path);
			return (pathname);
		}
		free(pathname);
		pathname = NULL;
		path_ptr = break_input_line(NULL, ":");
	}
	free(copy_path);
	return (NULL);
}
