#include "monty.h"

/**
 * pint - function to print value at top of stack
 * @stack: pointer to the stack structure
 * @line_number: line number in bytecode
 */

void pint(struct Stack *stack, int line_number)
{
	if (stack->top == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", stack->data[stack->top]);
	}
}
