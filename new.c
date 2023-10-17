#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...) {
  int Chars_Print = 0;
  va_list List_Of_Arguments;

  if (format == NULL) {
    return -1;
  }

  va_start(List_Of_Arguments, format);

  while (*format) {
    if (*format != '%') {
      write(1, format, 1);
      Chars_Print++;
    } else {
      format++;

      switch (*format) {
        case '%':
          write(1, format, 1);
          Chars_Print++;
          break;
        case 'c': {
char Charactera = va_arg(List_Of_Arguments, int);
if (Charactera == '\0')
{
break;
}
write(1, &Charactera, 1);
Chars_Print++;
          break;
		}
        case 's': {
          char *string = va_arg(List_Of_Arguments, char *);
          // Fix: Copy the string to a temporary buffer before writing it
          char buffer[1024];
          strncpy(buffer, string, sizeof(buffer));
          // Ensure that the buffer is terminated with a null character
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
int main() {
	int mad = 'h';
	mad = _printf("Let's try to printf a simple sentence.\n");
	printf("%c\n", mad);
	_printf("Leo\n");
	_printf("%s\n", "string");
	_printf("%c\n", 'b');
	_printf("%%\n");
	return 0;

}
