#include "main.h"

/**
 * print_hexa_upper - print upper case hex chars
 * @types: type args
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: int
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
