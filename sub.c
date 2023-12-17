#include "monty.h"

/**
 * sub - subtracts top elemnt of stack from second top element
 * @stack: double pointer to beginning of stack_t list
 * @line_number: number of line in file
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack is too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
