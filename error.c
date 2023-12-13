#include "monty.h"
/**
*error - handle error
*@first: pointer of pointer to the stack
*/
void error(stack_t **first)
{
	fclose(args.file);
	free(args.buf);
	stack_free(*first);
	exit(EXIT_FAILURE);
}
