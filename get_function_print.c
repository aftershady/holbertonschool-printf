#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

int (*get_function_print(char letter))(va_list, int)
{
	type check_type[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_modulo},
		{'\0', NULL}};

	int i = 0;
	while (check_type[i].letter != '\0' && check_type[i].letter != letter)
	{
		i++;
	}
	return check_type[i].pointer_function;
	return(0);
}
