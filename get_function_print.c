#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * get_func_print - check what is the type of va_arg to display
 * @format: string of printf where she stops
 * @list: list of arguments in variadic function
 * Descrition : check if there is a char after%, if there is print the
 * argument of the variadic function who correspond, if not printf just the %
 * Return: number of characters print in this function and function called
 */
int get_func_print(const char *format, va_list list)
{
	int add_size = 0;
	int i = 0;
	int is_valid = 0;
	type check_type[] = {
		{'c', print_char},
		{'s', print_string},
		{0, 0}};

	format++;
	while (check_type[i].letter != 0)
	{
		if (*format == '%')
		{
			format++;
			_putchar('%');
			add_size++;
			is_valid = 1;
			break;
		}
		else if (*format == check_type[i].letter)
		{
			format++;
			add_size = check_type[i].pointer_function(list);
			is_valid = 1;
			break;
		}
		i++;
	}
	if (is_valid == 0)
	{
		exit(-1);
		add_size++;
	}
	return (add_size);
}
