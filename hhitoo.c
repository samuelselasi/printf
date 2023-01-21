#include "main.h"

/**
 * hhitoo - integer to octal(short short)
 * @list: argument to convert
 * Return: a string
 */

char *hhitoo(va_list list)
{
	unsigned char digits, digitTest;
	int count, i;
	char *output;

	digits = (unsigned char) va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 8;
		count++;
	}
	digitTest = digits;
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		output[i] = ((digitTest % 8) + '0');
		digitTest /= 8;
	}
	output[count] = '\0';
	return (output);
}
