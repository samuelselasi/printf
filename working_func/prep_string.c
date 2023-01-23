#include "main.h"

/**
 * prep_string - prepare character string for printf
 * @str: the string
 * @spec: specifier
 *
 * Return: string
 */

char *prep_string(char *str, specifier spec)
{
	char *ret, *ptr, *hold = str;
	unsigned int len;

	if (str == NULL)
	{
		if (spec.specifier != 's' && spec.specifier != 'c')
			free(hold);
		return (null());
	}
	len = _strlen(str);
	if (spec.specifier == 'c' && *str == 0)
		len++;
	if (len > spec.precision && spec.precisionflag == 1)
		len = spec.precision;

	if (len < spec.width && spec.widthflag == 1)
	{
		ret = malloc((spec.width + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(hold);
			return (NULL);
		}
		ptr = ret;
		if (spec.left == 0)
		{
			while (len < spec.width--)
				*ptr++ = ' ';
			while (len--)
				*ptr++ = *str++;
			*ptr = 0;
		}
		else
		{
			spec.width -= len;
			while (len--)
				*ptr++ = *str++;
			while (spec.width--)
				*ptr++ = ' ';
			*ptr = 0;
		}
	}
	else
	{
		ret = malloc((len + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(hold);
			return (NULL);
		}
		ptr = ret;
		while (len--)
			*ptr++ = *str++;
		*ptr = 0;
	}
	if (spec.specifier != 's' && spec.specifier != 'c')
		free(hold);
	return (ret);
}
