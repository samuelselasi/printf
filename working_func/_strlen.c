#include "main.h"

/**
 * _strlen - return length string
 * @str: the string
 * Return: length
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str++)
	{
		len++;
	}
	return (len);
}
