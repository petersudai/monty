#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to beginning of stack_t list
 * @line_number: Line number in file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
