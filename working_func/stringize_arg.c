#include "main.h"

/**
 * stringize_arg - Send va_arg to right function,
 * or return string for % or %c
 * @list: va_list to select
 * @spec: specifier struct
 * @freeflag: free malloc
 *
 * Return: string to add to buffer
 */

char *stringize_arg(va_list list, specifier spec, unsigned int *freeflag)
{
	static char tmpstr[2] = {0, 0};
	char *tmp;

	switch (spec.specifier)
	{
	case 'n':
		tmpstr[0] = 0;
		return (tmpstr);
	case '%':
		tmpstr[0] = '%';
		return (tmpstr);
	case 'c':
		tmpstr[0] = (char) va_arg(list, int);
		*freeflag = 1;
		return (prep_string(tmpstr, spec));
	case 's':
		*freeflag = 1;
		tmp = va_arg(list, char*);
		return (prep_string(tmp, spec));
	case 'd':
	case 'i':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(litos(list), spec));
		if (spec.length == -1)
			return (prep_numeric(hitos(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhitos(list), spec));
		return (prep_numeric(itos(list), spec));
	case 'b':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(luitob(list), spec));
		if (spec.length == -1)
			return (prep_numeric(huitob(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhuitob(list), spec));
		return (prep_numeric(uitob(list), spec));
	case 'u':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(lutos(list), spec));
		if (spec.length == -1)
			return (prep_numeric(hutos(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhutos(list), spec));
		return (prep_numeric(utos(list), spec));

	case 'o':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(litoo(list), spec));
		if (spec.length == -1)
			return (prep_numeric(hitoo(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhitoo(list), spec));
		return (prep_numeric(itoo(list), spec));
	case 'x':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(litox(list), spec));
		if (spec.length == -1)
			return (prep_numeric(hitox(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhitox(list), spec));
		return (prep_numeric(itox(list), spec));
	case 'X':
		*freeflag = 1;
		if (spec.length == 1)
			return (prep_numeric(litoX(list), spec));
		if (spec.length == -1)
			return (prep_numeric(hitoX(list), spec));
		if (spec.length < -1)
			return (prep_numeric(hhitoX(list), spec));
		return (prep_numeric(itoX(list), spec));
	case 'r':
		*freeflag = 1;
		tmp = rev_str(va_arg(list, char*));
		if (tmp != NULL)
			return (prep_string(tmp, spec));
		return (NULL);
	case 'R':
		*freeflag = 1;
		tmp = rot13(va_arg(list, char*));
		if (tmp != NULL)
			return (prep_string(tmp, spec));
		return (NULL);
	case 'S':
		*freeflag = 1;
		tmp = print_hidden(va_arg(list, char*));
		if (tmp != NULL)
			return (prep_string(tmp, spec));
		return (NULL);
	case 'p':
		*freeflag = 1;
		return (prep_numeric(litox(list), spec));
	}
	return (NULL);
}
