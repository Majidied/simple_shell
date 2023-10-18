#include "shell.h"

/**
 * _execute - to execute the shell commands.
 * @command: input command by user.
 * @argv: ......
 * Return: integer.
 */

int _execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freecmd(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freecmd(command);
	}
	return (WEXITSTATUS(status));
}
