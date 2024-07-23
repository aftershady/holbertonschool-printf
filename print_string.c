#include "main.h"
#include <stdarg.h>

/**
 * print_string - printf a string with putchar
 * @list: list of variadic function
 * Description: print an argument who is a string and count the number of char
 * printed
 * Return: number of character printed
 */
int print_string(va_list list)
{
	char *ptr;
	int i = 0;

	ptr = va_arg(list, char *); /** extracting the string */
	if (ptr != 0) /** A GERER */
	{
		while (ptr[i] != '\0')
		{
			_putchar(ptr[i]); /**  print every charactère of the string**/
			i++;
		}
	}
	return (i); /** length of the string */
}
