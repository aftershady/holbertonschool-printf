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
	char *ptr;
	int i;

	(void)size;

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
int print_integer(va_list list, int size)
{
	int integer = va_arg(list, int);
	char str[12];
	char temp[12];
	int i = 0;
	int j;


	(void)size;
	if(integer != 0)
	{
		while((integer / 10) != 0)
		{
			temp[i] = (integer % 10);
			integer = (integer / 10);
			i++;
		}
		temp[i] = (integer % 10);
		for(j = 0; i != 0; j++, i--)
		{
			str[j] = temp[i];
		}
		for(i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i] + '0');

		}
		_putchar(str[i] + '0');
	}

	else
	{
		_putchar('0');
		j = 1;
	}
	return (j);
}
