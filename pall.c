#include "monty.h"

/**
 * pall - prints all values on stack
 * @stack :double pointer to the beginning ofstack structure
 * @line_number: number of line in the monty bytcode file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	if (!current)
	{
		fprintf(stderr, "L%d: can't pall, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
