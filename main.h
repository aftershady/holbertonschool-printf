#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct type - contain a character and a pointer of function
 * @letter: can contain a character
 * @pointer_function: can contain a function who return a int
 */
typedef struct type
{
char letter;
int (*pointer_function)(va_list);
} type;

int _putchar(char c);
int _printf(const char *format, ...);
int get_func_print(const char *format, va_list);
int print_char(va_list);
int print_string(va_list);

#endif
