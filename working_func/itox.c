#include "main.h"

/**
 * itox - convert to hex
 * @list: args
 * Return: string
 */

char *itox(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}