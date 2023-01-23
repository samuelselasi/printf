#include "main.h"

/**
 * print_percent - print %
 * @types: type args
 * @buffer: buffer
 * @flags: find active flags
 * @width: width
 * @precision: precision
 * @size: size
 *
 * Return: int
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
