#include "main.h"

/**
 * convert_size_unsgnd - add unsigned number
 * @num: the number
 * @size: size
 *
 * Return: num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}

	return ((unsigned int)num);
}
