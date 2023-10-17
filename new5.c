#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf_char - Print a character.
 * @list: Variable argument list.
 * Return: Number of characters printed.
 */
int _printf_char(va_list *list)
{
  char character = va_arg(*list, int);
  write(1, &character, 1);
  return 1;
}

/**
 * _printf_string - Print a string.
 * @list: Variable argument list.
 * Return: Number of characters printed.
 */
int _printf_string(va_list *list)
{
  char *string = va_arg(*list, char *);
  write(1, string, strlen(string));
  return strlen(string);
}

/**
 * _printf - Printf function.
 * @format: Format string.
 * ...: Variable arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
  int characters_printed = 0;
  va_list list;
  va_start(list, format);

  while (*format) {
    if (*format != '%') {
      write(1, format, 1);
      characters_printed++;
    } else {
      format++;

      switch (*format) {
        case '%':
          write(1, format, 1);
          characters_printed++;
          break;
        case 'c':
          characters_printed += _printf_char(&list);
          break;
        case 's':
          characters_printed += _printf_string(&list);
          break;
      }
    }

    format++;
  }

  va_end(list);

  return characters_printed;
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
