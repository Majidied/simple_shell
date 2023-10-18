#include "shell.h"

/**
 * main - simple shell fonction
 * @ac: count of arguments
 * @av: arguments
 * Return: 0 always.
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, i;
	(void) ac;
	(void) argv;
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		printf("%s", line);
		free(line);
		command = tokenizer(line);
		if (!command)
			continue;
		for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			free(command[i]), command[i] = NULL;
		}
		free(command), command = NULL;

		/*status = _execute(command, argv);*/
	}
}
