#include "monty.h"

/**
 * pchar - prints the char at the top ofstack
 * @stack: double pointer to beginning of stack
 * @line_number: line number in file
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
