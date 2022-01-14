#include "monty.h"

/**
 * op_push - Pushes an element to the stack
 * @stack: Top of the stack
 * @line_number: Value to the new element
 *
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
}

/**
 * op_pall - Prints all the values on the stack
 * @stack: Top of the stack
 * @line_number: Number of the line in the file .m
 *
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	line_number = line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	};
	free_stack(*stack);
}
