#include "shell.h"

/**
 * _strlen - length of a string
 * @s: input char
 * Return: lenght
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
