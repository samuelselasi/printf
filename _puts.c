#include "main.h"

/**
 * _puts - print a string followed by a newline
 * @s: the string
 * Return: len
 */

int _puts(char *s)
{
	long int len;

	while (*s)
	{
		write(1, s, 1);
		len++;
		s++;
	}
	return (len);
}
