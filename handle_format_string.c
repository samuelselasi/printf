#include "main.h"
/**
 * handle_format_string - handle the format string
 * @format: format string
 * @buffer: output buffer
 * @len: buffer length
 * @list: va_list
 *
 * Return: no. of chars in buffer
 */
int handle_format_string(char *format, char *buffer,
		unsigned int *len, va_list list)
{
	int printtotal = 0;
	char *tmp = 0, *ptr = 0;
	unsigned int freeflag = 0, charzero;
	specifier spec;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
			{
				spec.specifier = 'y';
				break;
			}
			spec = get_specifier(&format, list);
			if (spec.specifier == 'y')
				break;
			freeflag = 0;
			charzero = 0;
			tmp = stringize_arg(list, spec, &freeflag);
			if (tmp == NULL)
				break;
			ptr = tmp;
			while (*ptr || spec.width || (charzero == 0 &&
						spec.specifier == 'c'))
			{
				if (spec.width > 0)
					spec.width--;
				buffer[(*len)++] = *ptr++;
				charzero = 1;
				if (*len == 1024)
				{
					printtotal += write(1, buffer, 1024);
					*len = 0;
				}
			}
			if (freeflag)
				free(tmp);
		}
		else
			printtotal += buffer_const_char(&format, buffer, len);
	}
	return (printtotal);
}
