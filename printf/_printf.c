#include "main.h"

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
write(1, "(null)", 6);
return (6);
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
 * Return: The number of characters printed.
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
}
}
format++;
}
va_end(list);
return (characters_printed);
}

