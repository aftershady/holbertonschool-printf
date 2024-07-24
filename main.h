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
	int (*pointer_function)(va_list, int);
} type;

int (*get_function_print(char letter))(va_list, int);
int print_char(va_list list, int size);
int print_string(va_list list, int size);
int print_modulo(va_list list, int size);
int _printf(const char *format, ...);
int _putchar(char c);

#endif
