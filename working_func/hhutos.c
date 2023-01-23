#include "main.h"

/**
 * hhutos - convert unsigned to string (short short)
 * @list: vargs
 * Return: string
 */

char *hhutos(va_list list)
{
	unsigned char digits, digitTest;
	int count, i;
	char *result;

	digits = (unsigned char) va_arg(list, unsigned int);
	digitTest = digits;
	count = 0;
	while (digitTest > 0)
	{
		digitTest /= 10;
		count++;
	}
	digitTest = digits;
	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	for (i = count - 1; i >= 0; i--)
	{
		result[i] = (digitTest % 10 + '0');
		digitTest /= 10;
	}
	result[count] = '\0';
	return (result);
}
