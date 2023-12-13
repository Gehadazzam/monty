#include "monty.h"
/**
*check_func - itrate of the functions
*@buf: pointer
*@stack: pointer of pointer to the stack
*@count: unsigned int
*@file_d: the file open
*Return: integer
*/
int check_func(char *buf, stack_t **stack, unsigned int count, int file_d)
{
instruction_t func[] = {
{"push", mypush},
{"pall", my_pall},
{"pint", my_pint},
{"pop", mypop},
{"add", stack_add},
{"nop", f_nop},
{"swap", f_swap},
{"sub", stack_sub},
{"div", stack_div},
{"mul", stack_mul},
{"mod", stack_mod},
{"pchar", stack_pchar},
{NULL, NULL}
};
	unsigned int x = 0;
	char *function = strtok(buf, " \n\t");

	if (function && function[0] == '#')
		return (0);
	args.buf = strtok(NULL, " \n\t");
	while (func[x].opcode && function)
{
		if (strcmp(function, func[x].opcode) == 0)
{
			func[x].f(stack, count);
			return (0);
}
		x++;
}
	if (function && func[x].opcode == NULL)
{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, function);
		close(file_d), free(args.buf);
		stack_free(*stack), exit(EXIT_FAILURE);
}
	return (1);
}
