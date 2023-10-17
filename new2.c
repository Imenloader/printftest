#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
int Chars_Print = 0;
va_list List_Of_Arguments;
if (format == NULL)
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
switch (*format)
{
case '%':
write(1, format, 1);
Chars_Print++;
break;
case 'c':
{
char Charactera = va_arg(List_Of_Arguments, int);
if (Charactera == '\0')
{
break;
}
write(1, &Charactera, 1);
Chars_Print++;
break;
}
case 's':
{
char *string = va_arg(List_Of_Arguments, char *);
char buffer[1024];
strncpy(buffer, string, sizeof(buffer));
buffer[sizeof(buffer) - 1] = '\0';
write(1, buffer, strlen(buffer));
Chars_Print += strlen(buffer);
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
    return (0);
}
