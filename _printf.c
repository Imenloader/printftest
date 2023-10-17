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

}
