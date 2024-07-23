#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 *get_function_print - Selects the correct function to perform the operation
 * @letter: The specifier character.
 *
 *Return: A pointer to the corresponding function.
 *Reuturn: NULL if no valid specifier is found.
 **/

int (*get_function_print(char letter))(va_list, int)
{
	type check_type[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_modulo},
		{'\0', NULL}};

	int i = 0;
	
	while (check_type[i].letter != '\0')
	{
		if (check_type[i].letter == letter)
			return (check_type[i].pointer_function);
		i++;
	}

	return (NULL);
}
