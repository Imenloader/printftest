#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
int _printf(const char *format, ...)
{
int Chars_Print = 0;
va_list List_Of_Arguments;
if(format == NULL)
{
return -1;
}
va_start(List_Of_Arguments, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
Chars_Print++;
}
else
{
format++;
if (format == '\0')
break;
switch(*format)
{
case 'd':
{
int value = va_arg(List_Of_Arguments, int);
char buffer[32];
int length = sprintf(buffer, "%d", value);
write(1, buffer, length);
Chars_Print += length;
break;
}
case 'u':
{
unsigned int value = va_arg(List_Of_Arguments, unsigned int);
char buffer[32];
int length = sprintf(buffer, "%u", value);
write(1, buffer, length);
Chars_Print += length;
break;
}
case 'o':
{
unsigned int value = va_arg(List_Of_Arguments, unsigned int);
char buffer[32];
int length = sprintf(buffer, "%o", value);
write(1, buffer, length);
Chars_Print += length;
break;
}
case 'x':
{
unsigned int value = va_arg(List_Of_Arguments, unsigned int);
char buffer[32];
int length = sprintf(buffer, "%x", value);
write(1, buffer, length);
Chars_Print += length;
break;
}
case 'f':
{
double value = va_arg(List_Of_Arguments, double);
char buffer[32];
int length = sprintf(buffer, "%f", value);
write(1, buffer, length);
Chars_Print += length;
break;
}
case 'c':
{
char value = va_arg(List_Of_Arguments, int);
write(1, &value, 1);
Chars_Print++;
break;
}
case 's':
{
char *value = va_arg(List_Of_Arguments, char *);
int length = strlen(value);
write(1, value, length);
Chars_Print += length;
break;
}
case '%':
{
write(1, "%", 1);
Chars_Print++;
break;
}
default:
{
write(1, format, 1);
Chars_Print++;
break;
}
}
}
format++;
}
va_end(List_Of_Arguments);
return Chars_Print;
}
int main(void)
{
int len;
int len2;
unsigned int ui;
void *addr;
len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
addr = (void *)0x7ffe637541f0;
_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);
_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);
_printf("Unsigned:[%u]\n", ui);
printf("Unsigned:[%u]\n", ui);
_printf("Unsigned octal:[%o]\n", ui);
printf("Unsigned octal:[%o]\n", ui);
_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");
_printf("Address:[%p]\n", addr);
printf("Address:[%p]\n", addr);
len = _printf("Percent:[%%]\n");
len2 = printf("Percent:[%%]\n");
_printf("Len:[%d]\n", len);
printf("Len:[%d]\n", len2);
return (0);
}
