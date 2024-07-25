#include "main.h"
#include <stdio.h>
/**
 *_print_rev - print string in reverse
 *Description: reverse string
 *@s: pointer
 *Return: void
 */

void _print_rev(char *s)
{
	int x = 0;
	int y;

	while (s[x] != '\0')
	{
		x++;
	}
	y = x - 1;
	while (y >= 0)
	{
		_putchar(s[y]);
		y--;
	}
}
