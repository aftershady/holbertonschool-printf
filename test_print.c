#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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

int _putchar(char c);
int get_func_print(char *str, va_list, int siz);
int print_char(va_list list, int size);
int print_string(va_list list, int size);
int print_modulo(va_list list, int);

#endif

#include <stdarg.h>
#include <stdio.h>
/** print functions for each type */
int print_char(va_list list, int size)
{
	char c;
	c = va_arg(list, int);
	_putchar(c);
	return (1); /** always one */
}

int print_modulo(va_list list, int size)
{
	_putchar('%');
	return (1); /** always one */
}

int print_string(va_list list, int size)
{
	char *ptr;
	*ptr = va_arg(list, char *); /** extracting the string */
	int i = 0;

	if (ptr != NULL) /** A GERER */
	{
	while (ptr[i] != '\0')
	{
		putchar(ptr[i]); /**  print every charactère of the string**/
		i++;
	}

	return (i); /** length of the string */
}

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int (*get_function_print(char letter))(va_list, int)
{
	type check_type[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_modulo},
		{'\0', NULL}};

	int i = 0;
	while (check_type[i].letter != '\0' && check_type[i].letter != letter)
	{
		i++;
	}
	return check_type[i].pointer_function;
}

/** _printf   fonction */


int _printf(const char *format, ...)
{
	va_list list;
	int size = 0;
	int *str = format;

	va_start(list, format);
	if (format)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				str++; // check the next character  if its %c %% or %s
				if (*str != '\0')
				{
					int (*func)(va_list, int) = get_function_print(*str);
					if (func)
					{
						size += func(list, size); /** adds number of %c or %s to size */
					}
					else /** if no special charactér found (NO %c %s or %%) */
					{
						_putchar('%');
						_putchar(*str);
						size += 2; /**  the modulo  + the  char after */
					}
					str++; /** continue */
				}
			}
			else
			{
				_putchar(*str); /** no modulo found */
				size++;
			}
			str++;
		}
		va_end(list);
		return size;
	}
}

int _putchar(char c);
int get_func_print(char *str, va_list, int siz);
int print_char(va_list, int size);
int print_string(va_list, int size);
int print_modulo(va_list, int);
/** Programme principal pour tester _printf */
void main(void)
{
	int testx;

	// Test pour %c
	testx = _printf("Test de %c\n", 'A');
	printf("Nombre de caractères imprimés : %d\n", testx);
}
