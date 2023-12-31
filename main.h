<<<<<<< HEAD
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>



/*Mandatory functions*/
int _printf(const char *format, ...);
int op_ch(va_list arg);
int op_st(va_list arg);
int op_nu(va_list arg);

/*Advanced functions*/
int op_fl(va_list arg);
int op_bi(va_list arg);
int _rot13(va_list agr);

/*Other useful functions*/
int count(const char *str);
int _putchar(char c);
void print_number(int n);

/**
* struct specifier - structure
* @ch: character with the specifier
* @f: Function associated
*
* Description: Define a new data type specifier that
* select the function to execute for the specifier selected.
*/
typedef struct specifier
{
	char *ch;
	int (*f)(va_list str);
} specifier;

#endif
=======
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
>>>>>>> 67782eab519eda037fcc1e37e07439097c499a1f
