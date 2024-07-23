#include "main.h"
#include <stdarg.h>

/**
 * print_char - print a single character
 * @list: list of variadic function
 * Description: call made after find a %c in the string
 * print by the function _printf, this function will only
 * print one char if the argument is a char
 * Return: len of string incremented
 */
int print_char(va_list list)
{
	int add_size = 0;
	char letter = va_arg(list, int);

	if (letter != '\0')
	{
		_putchar(letter);
		add_size++;
	}
	return (add_size);
}

