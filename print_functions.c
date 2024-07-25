#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 *print_char - Prints a character
 *@list: va_list containing the character to print
 *@size: number of arguments
 * Return: Number of characters printed (always 1)
 **/
int print_char(va_list list)
{

	_putchar(va_arg(list, int));
	return (1); /** always one */
}

/**
 *print_modulo - Prints a modulo
 *@list: va_list containing the string to print
 *@size: number of arguments
 *Return: Number of characters printed (length of the string)
 */
int print_modulo(va_list list)
{

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
int print_string(va_list list)
{
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
/**
*print_integer - function that Prints an integer as characters.
*@list: A list of arguments containing the integer to print.
*@size: Format size
*
*Return: the number of character printed.
**/

int print_integer(va_list list)
{
	int integer = va_arg(list, int);
	char str[12];
	int i;
	int is_negative = 0; /** initialising the flag for checking the */


	if (integer < 0) /** checcking if the number is negative */
	{	is_negative = 1; /** the flag set to 1 */
		integer = -integer; /** transforming it to negative number */
	}
	if (integer != 0)
	{
		for (i = 0; (integer / 10) != 0; i++)
		{	str[i] = (integer % 10) + '0';
			integer = (integer / 10);
		}
		str[i] = (integer % 10) + '0';
		i++;
		str[i] = '\0';
		if (is_negative) /** the number is negative*/
		{	_putchar('-'); /** printing the negative signe befor */
			i++; }
		_print_rev(str);
	}
	else
	{	_putchar('0');
		i = 1; }
	return (i);
}
