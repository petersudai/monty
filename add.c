#include "monty.h"

/**
 * add - adds top two elements of stack
 * @stack: double pointer to beginning of the stack_t list
 * @line_number: number of line in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short|n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
