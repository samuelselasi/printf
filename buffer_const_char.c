#include "main.h"

/**
 * buffer_const_char - put const format chars into buffer
 * @format: format string
 * @buffer: output buffer
 * @len: buffer length
 *
 * Return: no. of chars in buffer
 */

int buffer_const_char(char **format, char *buffer, unsigned int *len)
{
	int printtotal = 0;

	while (**format != 0 && **format != '%')
	{
		buffer[(*len)++] = **format;
		(*format)++;

		if (*len == 1024)
		{
			write(1, buffer, 1024);
			*len = 0;
			printtotal += 1024;
		}
	}
	return (printtotal);
}
