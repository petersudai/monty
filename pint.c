#include "monty.h"

/**
 * pint - function to print value at top of stack
 * @stack: pointer to the beginning of stack structure
 * @line_number: line number in bytecode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
