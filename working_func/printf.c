#include "main.h"

/**
 * _printf - print formatted string with args
 * @format: format string
 * Return: char, or -1 if error
 */

int _printf(char *format, ...)
{
	char *tmp = 0, *ptr = 0, buffer[1024];
	unsigned int len =  0, freeflag = 0, charzero, printtotal = 0;
	int lenr = 0;
	va_list list;
	specifier spec;

	tmp = buffer;
	if (format == NULL)
		return (-1);
	tmp = buffer;
	va_start(list, format);
	if (ifputs(format))
	{
		printtotal = _puts(va_arg(list, char *));
		va_end(list);
		return (printtotal);
	}
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
			while (*ptr || spec.width || (charzero == 0 && spec.specifier == 'c'))
			{
				if (spec.width > 0)
					spec.width--;
				buffer[len++] = *ptr++;
				charzero = 1;
				if (len == 1024)
				{
					lenr = write(1, buffer, 1024);
					if (lenr == -1)
						return (-1);
					printtotal += lenr;
					len = 0;
				}
			}
			if (freeflag)
				free(tmp);
		}
		else
			printtotal += buffer_const_char(&format, buffer, &len);
	}
	va_end(list);
	lenr = write(1, buffer, len);
	if (lenr == -1 || spec.specifier == 'y')
		return (-1);
	printtotal += lenr;
	if (tmp == NULL)
		return (-1);
	return (printtotal);
}
