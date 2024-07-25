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

int (*get_function_print(char letter))(va_list);
int print_char(va_list list);
int print_string(va_list list);
int print_modulo(va_list list);
void _print_rev(char *s);
int print_integer(va_list list);
int _printf(const char *format, ...);
int _putchar(char c);

#endif
