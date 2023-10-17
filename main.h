#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGINED 2




/*_printf.c module */
int _printf(const char *format, ...);
#endif 
