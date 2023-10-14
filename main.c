#include "shell.h"

/**
 * main - simple shell fonction
 * @ac: count of arguments
 * @av: arguments
 * Return: 0 always.
 */

int main(int ac, char **argv)
{
	char*line = NULL;
	/*char **command = NULL;*/
	int status = 0;
	(void) ac;
	(void) argv;
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		printf("%s", line);
		free(line);
		/*command = tokenizer(line);

		status = _execute(command, argv);*/
	}
}
