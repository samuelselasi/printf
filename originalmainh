#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * struct specifier - specifiers for printf
 * @width: field width
 * @precision: field precision
 * @length: type length. h/l flags. 0 default, +1 per l, -1 per h
 * @widthflag: tell if width is set
 * @precisionflag: tell if precision is set
 * @left: left justify, '-'. 0 for right, 1 for left
 * @sign: force sign, '+'. 0 for no, 1 for yes
 * @space: space pad left side of positive numbers if leading 0s. 0 no 1 yes
 * @zero: zero pad numbers up to width. 0 for no, 1 for yes.
 * @zerox: add leading 0, 0x, or 0X to o, x or X specifiers. 0 no 1 yes
 * @specifier: type to print, c, s, d, x, ....
 *
 * Description - more...
 */

typedef struct specifier
{
	unsigned int width;
	unsigned int precision;
	int length;
	char widthflag;
	char precisionflag;
	char left;
	char sign;
	char space;
	char zero;
	char zerox;
	char specifier;
} specifier;

int _printf(char *format, ...);
int buffer_const_char(char **format, char *buffer, unsigned int *len);
char *stringize_arg(va_list list, specifier spec, unsigned int *freeflag);
specifier get_specifier(char **format, va_list list);

char *prep_string(char *str, specifier spec);
char *prep_numeric(char *str, specifier spec);

int _strlen(char *str);
int _puts(char *s);
int ifputs(char *s);

char *itos(va_list list);
char *hitos(va_list list);
char *litos(va_list list);
char *hhitos(va_list list);

char *uitob(va_list list);
char *luitob(va_list list);
char *huitob(va_list list);
char *hhuitob(va_list list);

char *utos(va_list list);
char *hutos(va_list list);
char *hhutos(va_list list);
char *lutos(va_list list);

char *itoo(va_list list);
char *litoo(va_list list);
char *hitoo(va_list list);
char *hhitoo(va_list list);

char *itox(va_list list);
char *litox(va_list list);
char *hitox(va_list list);
char *hhitox(va_list list);

char *itoX(va_list list);
char *hitoX(va_list list);
char *hhitoX(va_list list);
char *litoX(va_list list);

char *rev_str(char *str);
char *rot13(char *str);
char *print_hidden(char *str);
char *null(void);

char *nil(void);

#endif
