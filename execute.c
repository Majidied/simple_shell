#include "shell.h"

/**
 * _execute - to execute the shell commands.
 * @command: input command by user.
 * @argv: ......
 * @idx: .........
 * Return: integer.
 */

int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		freecmd(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freecmd(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freecmd(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
