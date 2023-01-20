#include "main.h"

/**
 * ifputs - check if prinft format is puts
 * @str: the string
 * Return: 1 if puts, 0 otherwise
 */

int ifputs(char *str)
{
	if (str[0] == '%' && str[1] == 's' && str[2] == '\n' && str[3] == 0)
	{
		return (1);
	}
	return (0);
}
