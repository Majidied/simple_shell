#include "shell.h"
/**
 * _strcat - concatenate two strings.
 * @dest: string to destiny
 * @src: string to source
 * Return: concatenate string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, lenght = 0;

	while (*(dest + lenght) != '\0')
		lenght++;
	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dest + lenght) = *(src + i);
		lenght++;
	}
	*(dest + lenght) = '\0';

	return (dest);
}
