#include "monty.h"

/**
 * swap - swaps the top two elements of stack
 * @stack: double pointer to beginning of stack_t list
 * @line_number: line number in file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)-> next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	*stack = temp;
}
