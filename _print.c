#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 **/

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
				format++; /*check the next character  if its %c %% or %s*/
				if (*format != '\0')
				{
					int (*func)(va_list) = get_function_print(*format);

					if (func)
					{
						size += func(list); /** adds number of %c or %s to size */
					}
					else /** if no special charactér found (NO %c %s or %%) */
					{
						_putchar('%');
						_putchar(*format);
						size += 2; /**  the modulo  + the  char after */
					}
				}
			}
			else
			{
				_putchar(*format); /** no modulo found */
				size++;
			}
			format++;
		}
	}
	va_end(list);
	return (size);
}
