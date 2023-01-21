#include "main.h"

/**
 * hhitos - convert int to string (short short)
 * @list: variadic args
 * Return: string
 */

char *hhitos(va_list list)
{
	int count, i, neg, absMod;
	char digits, digitTest;
	char *output;

	digits = (char) va_arg(list, int);
	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}
