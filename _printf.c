<<<<<<< HEAD
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/**
 * _printf_char - Print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int _printf_char(char c)
{
write(1, &c, 1);
return (1);
}

/**
 * _printf_string - Print a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int _printf_string(char *s)
{
if (s == NULL)
{
return (0);
}
else
{
write(1, s, strlen(s));
return (strlen(s));
}
}

/**
 * _printf - Printf function.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
int characters_printed = 0;
va_list list;
va_start(list, format);
while (*format)
{
if (*format != '%')
{
characters_printed += _printf_char(*format);
}
else
{
format++;
switch (*format)
{
case '%':
characters_printed += _printf_char('%');
break;
case 'c':
characters_printed += _printf_char(va_arg(list, int));
break;
case 's':
characters_printed += _printf_string(va_arg(list, char *));
break;
case 'd':
characters_printed += printf("%d", va_arg(list, int));
break;
case 'i':
characters_printed += printf("%i", va_arg(list, int));
break;
default:
return (0);
}
}
format++;
}
va_end(list);
return (characters_printed);
=======
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
int Chars_Print = 0;
va_list List_Of_Arguments;
if (format == NULL)
{
return -1;
}
va_start(List_Of_Arguments, format);
while (*format) {
if (*format != '%')
{
 write(1, format, 1);
 Chars_Print++;
}
else
{
format++;
}
if (format == '\0')
{
break;
}
if (*format == '%')
{
write(1, format, 1);
Chars_Print++;
}
else if (*format == 'c')
{
char Charactera = va_arg(List_Of_Arguments, int);
if (Charactera == '\0')
{
break;
}
write(1, &Charactera, 1);
Chars_Print++;
}
else if (*format == 's')
{
char *infinty_strings = va_arg(List_Of_Arguments, char*);
int infinty_strings_len = strlen(infinty_strings);
write(1, infinty_strings, infinty_strings_len);
Chars_Print += infinty_strings_len;
}
format++;
}
va_end(List_Of_Arguments);
return Chars_Print;
}


int main() {
	int mad = 'd';
		char g = 'f';

	mad = _printf("Let's try to printf a simple sentence.\n");
		  _printf("%c\n", g);
	printf("%c\n", mad);
	_printf("Leo\n");
	_printf("%s\n", "string");
	_printf("%c\n", 'b');
	_printf("%%\n");
	return 0;

>>>>>>> 67782eab519eda037fcc1e37e07439097c499a1f
}
