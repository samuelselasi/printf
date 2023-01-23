#include "main.h"

/**
 * null - returns "(null)"
 * Return: string
 */

char *null()
{
	char *ret, *ptr;
	char *null = "(null)";

	ret = malloc(7 * sizeof(char));
	ptr = ret;
	while (*null)
		*ptr++ = *null++;
	*ptr = 0;
	return (ret);
}
