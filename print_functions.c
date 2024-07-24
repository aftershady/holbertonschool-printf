#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *print_char - Prints a character
 *@list: va_list containing the character to print
 *@size: number of arguments
 * Return: Number of characters printed (always 1)
 **/
int print_char(va_list list, int size)
{
	(void)size;
	_putchar(va_arg(list, int));
	return (1); /** always one */
}

/**
 *print_modulo - Prints a modulo
 *@list: va_list containing the string to print
 *@size: number of arguments
 *Return: Number of characters printed (length of the string)
 */
int print_modulo(va_list list, int size)
{
	(void)size;
	(void)list;
	_putchar('%');
	return (1); /** always one */
}

/**
 *print_string - Prints a string
 *@list: va_list containing the string to print
 *@size: number of arguments
 *Return: Number of characters printed (length of the string)
 */
int print_string(va_list list, int size)
{
	(void)size;
	char *ptr;
	int i;

	ptr = va_arg(list, char *); /** extracting the string */
	i = 0;
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
