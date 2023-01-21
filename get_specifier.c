#include "main.h"

/**
 * get_specifier - get specifier
 * @format: format string to get info
 * @list: args passed to printf
 *
 * Return: specifier
 */

specifier get_specifier(char **format, va_list list)
{
	specifier spec;
	char *start;

	start = *format;
	spec.left = 0, spec.sign = 0, spec.space = 0;
	spec.zerox = 0, spec.zero = 0;
	while (**format == '-' || **format == '+' || **format == ' '
	       || **format == '#' || **format == '0')
	{
		if (**format == '-')
			spec.left = 1;
		else if (**format == '+')
			spec.sign = 1;
		else if (**format == ' ')
			spec.space = 1;
		else if (**format == '#')
			spec.zerox = 1;
		else
			spec.zero = 1;
		(*format)++;
	}
	spec.width = 0;	spec.widthflag = 0;
	if (**format == '*')
	{
		spec.widthflag = 1;
		spec.width = va_arg(list, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			spec.widthflag = 1;
			spec.width *= 10;
			spec.width += **format - '0';
			(*format)++;
		}
	}
	spec.precision = 1; spec.precisionflag = 0;
	if (**format == '.')
	{
		spec.precisionflag = 1;
		spec.precision = 0;
		(*format)++;
		if (**format == '*')
		{
			spec.precision = va_arg(list, int);
			(*format)++;
		}
		else
		{
			while (**format >= '0' && **format <= '9')
			{
				spec.precision *= 10;
				spec.precision += **format - '0';
				(*format)++;
			}
		}
	}
	spec.length = 0;
	while (**format == 'h')
	{
		(*format)++;
		if (spec.length > -2)
			spec.length--;
		else
			spec.length = 10;
	}
	while (**format == 'l')
	{
		(*format)++;
		if (spec.length >= 0)
			spec.length = 1;
		else
			spec.length = 10;
	}
	spec.specifier = **format;
	if (**format == 'p')
		spec.zerox = 1;
	if (spec.length == 10)
		spec.specifier = 'z';
	switch (spec.specifier)
	{
	case '%': case 's': case 'c': case 'i': case 'd':
	case 'x': case 'X': case 'b': case 'o': case 'u':
	case 'R': case 'r': case 'S': case 'p':
		(*format)++;
		break;
	case 0:
		spec.specifier  = 'y';
		if (spec.length == 0)
			break;
		break;
	default:
		*format = start;
		if (spec.length != 0)
			(*format)++;
		spec.specifier = '%';
		break;
	}
	return (spec);
}
