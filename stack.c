#include "monty.h"

/**
 *free_stack - Release memory space of a stack
 *@top: Top of the stack
 *
 **/
void free_stack(stack_t *top)
{
	if (!top)
		return;
	while (top->prev)
	{
		top = top->prev;
		free(top->next);
	}
	free(top);
}
