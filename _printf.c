#include <stdarg.h>
#include "main.h"


/**
 * _printf - printf a string with undefined values of differents types in it
 * @format: the string to print with %? values int it
 * Description: print the string character by character and check on the same
 * times if there is a % int the string, if there is, another function will
 * print the argument who is afiliated with
 * Return: the number of characters who will be print
 */
int _printf(const char *format, ...)
{
	va_list list;
	int size = 0;

	va_start(list, format);
	if (format)
	{
		while (*format != '\0')
		{
			if (*format == '%')
			{
				size += get_func_print(format, list);
				/* size += the return of function*/
				format += 2;
				/* pass the char after %? */
			}
			else
			{
				_putchar(*format);
				format++;
				size++;
			}
		}
	}
	va_end(list);
	return (size);
}
