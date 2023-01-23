#include "main.h"
/**
 * print_hexadecimal - print unsigned in hex chars
 * @types: type args
 * @buffer: buffer
 * @flags: find active flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: int
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
