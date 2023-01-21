#include "main.h"

/**
 * _printf - print formatted string with args
 * @format: format string
 * Return: char, or -1 if error
 */

int _printf(char *format, ...)
{
	char buffer[1024];
	unsigned int len = 0, printtotal = 0;
	va_list list;

	va_start(list, format);

	if (ifputs(format))
	{
		printtotal = _puts(va_arg(list, char *));
		va_end(list);
		return (printtotal);
	}

	printtotal = handle_format_string(format, buffer, &len, list);
	va_end(list);

	return (printtotal + write(1, buffer, len));
}
