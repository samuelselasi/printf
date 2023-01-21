#include "main.h"

/**
 * rev_str - reverse string
 * @str: the string
 * Return: reversed string
 */

char *rev_str(char *str)
{
	long int i = 0, len;
	char tmp, *ret, *ptr;

	if (str == NULL)
		return (null());
	len = _strlen(str);
	ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ret[len] = 0;
	ptr = ret;
	while (*str)
		*ptr++ = *str++;
	len--;
	while (i < len)
	{
		tmp = ret[i];
		ret[i++] = ret[len];
		ret[len--] = tmp;
	}
	return (ret);
}
