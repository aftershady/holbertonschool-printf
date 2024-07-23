#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
*print_char - Prints a character
*@list: va_list containing the character to print
*@int: number of arguments
* Return: Number of characters printed (always 1)
**/
int print_char(va_list list, int)
{
	_putchar(va_arg(list, int));
	return (1); /** always one */
}

/**
*print_modulo - Prints a modulo
*@list: va_list containing the string to print
*@int: number of arguments
*Return: Number of characters printed (length of the string)
*/
int print_modulo(va_list list, int)
{
	_putchar('%');
	return (1); /** always one */
}

/**
*print_string - Prints a string
*@list: va_list containing the string to print
*@int: number of arguments
*Return: Number of characters printed (length of the string)
*/
int print_string(va_list list, int)
{
	char *ptr;

	ptr = va_arg(list, char *); /** extracting the string */
	int i = 0;

	if (ptr != NULL)
	{
		while (ptr[i] != '\0')
		{
			_putchar(ptr[i]); /**  print every charactère of the string**/
			i++;
		}
	}
	return (i); /** length of the string */
}

