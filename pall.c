#include "monty.h"
/**
*my_pall - print out the stack
*
*@first: pointer of pointer to the stack
*
*@num: void int
*
*Return: void
*/
void my_pall(stack_t **first, unsigned int num)
{
stack_t *current = *first;
(void) num;
	if (first == NULL)
		return;
	while (current)
{
		printf("%d\n", current->n);
		current = current->next;
}
}
