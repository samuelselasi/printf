#include "main.h"

/**
 * uitob - convert to binary
 * @list: args
 * Return: string
 */

char *uitob(va_list list)
{
	unsigned int uiArg, uiArgTest;
	int counter, i;
	char *result;

	uiArg = va_arg(list, unsigned int);
	uiArgTest = uiArg;
	counter = 0;
	while (uiArgTest != 0)
	{
		uiArgTest /= 2;
		counter++;
	}
	result = malloc(sizeof(char) * (counter + 1));
	if (result == NULL)
		return (NULL);
	uiArgTest = uiArg;
	for (i = counter - 1; i >= 0; i--)
	{
		result[i] = ((uiArgTest % 2) + '0');
		uiArgTest /= 2;
	}
	result[counter] = '\0';
	return (result);

}
