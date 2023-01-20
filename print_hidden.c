#include "main.h"

/**
 * print_hidden - prints string and non printable chars
 * @str: the string
 * Return: hidden string
 */

char *print_hidden(char *str)
{
	char *output, *ptr;
	long int i, len = 0;

	if (str == NULL)
		return (null());
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			len += 3;
		len++;
	}
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	for (ptr = output; *str; str++)
	{
		if (*str < 32 || *str >= 127)
		{
			*ptr++ = '\\';
			*ptr++ = 'x';
			*ptr++ = *str / 16 > 9 ? (*str / 16) + 55 : (*str / 16) + '0';
			*ptr++ = *str % 16 > 9 ? (*str % 16) + 55 : (*str % 16) + '0';
		}
		else
			*ptr++ = *str;
	}
	*ptr = 0;
	return (output);
}
