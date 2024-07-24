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
	const char *str;

	str = format;
	va_start(list, format);
	if (format)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				str++; /*check the next character  if its %c %% or %s*/
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
				}
			}
			else
			{
				_putchar(*str); /** no modulo found */
				size++;
			}
			str++;
		}
	}
	va_end(list);
	return (size);
}
