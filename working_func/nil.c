#include "main.h"

/**
 * nil - returns "(nil)"
 * Return: string
 */

char *nil()
{
	char *ret, *ptr;
	char *nil = "(nil)";

	ret = malloc(6 * sizeof(char));
	ptr = ret;
	while (*nil)
	{
		*ptr++ = *nil++;
	}
	*ptr = 0;
	return (ret);
}
