#include "monty.h"
/**
*node_add - add new node to double linked list
*@first: pointer of pointer to the stack
*@num: integer to be addes
*Return: void
*/
void node_add(stack_t **first, int num)
{
stack_t *current, *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n"), exit(0);
	current = *first;
	if (current)
		current->prev = new_node;
	new_node->prev = NULL;
	new_node->next = *first;
	new_node->n = num;
	*first = new_node;
}
/**
*queue_add - add a node to quque
*@first: pointer oof pointer to the stack
*@num: integer to be addes
*Return: void
*/
void queue_add(stack_t **first, int num)
{
stack_t *current, *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n"), exit(0);
	current = *first;
	new_node->n = num;
	new_node->next = NULL;
	if (current)
		while (current)
			current++;
	else if (!current)
{
		*first = new_node;
		new_node->prev = NULL;
}
	else
{
		current->next = new_node;
		new_node->prev = current;
}
}
