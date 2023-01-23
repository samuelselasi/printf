#include "main.h"

/**
 * lutos - convert unsigned to string (long)
 * @list: vargs
 * Return: string
 */

char *lutos(va_list list)
{
	unsigned long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned long int);
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
