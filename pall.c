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

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
